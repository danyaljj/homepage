%%
% Gausse-Seidel method for solving load-flow problem
% By: Daniel Khashabi, December, 2010
%%
clc
clear all

% number of buses:
n = 6;

% Acive power:
P = [0.7   -2.4    3.2   -1.6   -2.4    6.0];

% bus voltages:
V = [1 1 1 1 1 1];

% type of buses:
%   1: PQ
%   2: PV
%   3: Slack
type = [2 1 2 1 1 3];

% Reactive power:
Q = [0    -0.4       0    -0.24    -0.4         0];

% Admitance Matix:
% just lower trangle:
% Y   = [(0.39-1.56j)+(1.17-4.7j)  inf                        inf                               inf                           inf                       inf
%         0               2*(1.17-4.7j)+(0.58-2.35j)        inf                               inf                           inf                       inf
%         0                     -2*(1.17-4.7j)        2*(1.17-4.7j)+3*(1.17-4.7j)       inf                           inf                       inf
%         -(1.17-4.7j)             -(0.58-2.35j)                     0                   4*(0.23-0.94j)+(0.39-1.56j)+(0.58-2.35) inf                 inf
%         -(1.17-4.7j)               0                    -3*(1.17-4.7j)                     0              3*(1.17-4.7j)+(1.17-4.7j)           inf
%         0                          0                          0                         -4*(0.23-0.04j)                   0                    4*(0.23-0.04j)
%        ];

Y = makeYBUS();
% 
% for i=1:n
%     for j=1:i-1
%         Y(j,i) = Y(i,j);
%     end
% end

% Maximum Error:
EPS = 1e-6;

% Maximum number of iterations:
maxIter=50000;

err = 100; % initial value of error
itr=1; % iteration number
while(err>EPS && itr<maxIter )
    vP=V;
    for i = 1:n
        if type(i)~=3  % not slack
            currentTmp = 0;
            for k = 1:n,
                if i ~= k
                    currentTmp = currentTmp + Y(i,k)*V(k);
                end
            end
            if type(i) == 2,
                Q(i) = -imag(conj(V(i))*(currentTmp+Y(i,i)*V(i)));
                vTmp = V(i);
            end
            V(i) = ((P(i)-1i*Q(i))/conj(V(i)) - currentTmp)/Y(i,i);
            %disp(['Debug: Angle regulation: V(', num2str(i), '] ', num2str(abs(V(i)))]);
            %disp(['Debug: Current Tmp: ', num2str(currentTmp)]);
            
            if type(i) ==  2
                %vTmp
                %disp('Debug: Angle regulation: ');
                V(i) = 1i*imag(V(i)) + sqrt((abs(vTmp))^2-(imag(V(i)))^2);
                %V(i) = abs(vTmp)*cos(angle(V(i))) + 1i*abs(vTmp)*sin(angle(V(i)));
                abs(V)
                %disp(['Debug: Angle regulation: V(', num2str(i), '] ', num2str(abs(V(i)))]);
            end
        end
%         pause
    end
    err=max(abs(V-vP));
    itr=itr+1;
end

disp('-----------------------------');
disp(['Results after ', num2str(itr), ' iterations: '])

for i=1:n
    disp(['  V(',num2str(i),')= ', num2str(abs(V(i))),'<',num2str(rad2deg(angle(V(i))))]);
end
I = (Y*V')';
disp(['Currents of buses are : ', num2str(abs(I))])
S =  V.*conj(I);
disp(['Injected real power of buses are : ', num2str(real(S))])
disp(['Injected reactive power of buses are : ', num2str(imag(S))])
PLoss = real(sum(S));
disp(['Total loss in lines are : ', num2str(PLoss)]);
disp(['|PLoss|/|PGeneration| = % ', num2str(PLoss/sum(P(P>0))*100)])

deltaV = zeros(n, n);
for i=1:n
   for j=1:n
       deltaV(i,j) = abs(V(i)-V(j));
   end
end
SLine = deltaV.^2.*conj(Y);
PLine = real(SLine);  %% must not be lower than power capacity
