%%
% Gausse-Seidel method for solving load-flow problem
% By: Daniel Khashabi, December, 2010
%%
clear all

% number of buses:
disp('Enter the following parameters :')
n = input('Enter number of buses: ');

% type of buses:
%   1: PQ
%   2: PV
%   3: Slack
disp('-----------------------------');
disp('Enter 1 for PQ bus')
disp('Enter 2 for PV bus')
disp('Enter 3 for slack bus')
type = zeros(1,n);
for i=1:n
   type(1,i) = input(['Enter types of bus', ...
       num2str(i), ' : ']);
end

% Acive power:
P = ones(1,n); % 1 initial value for PQ buses
disp('Enter Active Powers: ');
disp('-----------------------------');
for i=1:n
    if type(1,n)~=3  % not for slack bus:
        P(1,i) = input(['Active power for the bus ', num2str(i), ' : ']);   
    end
end

% bus voltages:
disp('-----------------------------');
disp('Enter Votages: ');
V = zeros(1,n);
for i=1:n
    if type(1,i) == 2  % for PV buses:
        V(1,i) = input(['Voltage for the bus ', num2str(i), ' : ']);   
    end
end

% Reactive power:
disp('-----------------------------');
disp('Enter Reactive Powers: ');
Q = zeros(1,n);
for i=1:n
    if type(1,i) == 1  % for PQ buses:
        Q(1,i) = input(['Reactive power for the bus ', num2str(i), ' : ']);   
    end
end

% Admitance Matix:
disp('-----------------------------');
disp('Values of addmitance matrix: (just lower traingle)');
Y = zeros(n,n);
for i=1:n
    for j=1:i
        Y(i,j) = input(['Y(',num2str(i), ...
            ',',num2str(j),')']);
    end
end
for i=1:n
    for j=1:i-1
        Y(j,i) = Y(i,j);
    end
end

% Maximum Error:
disp('-----------------------------');
EPS = 0.0001; 
EPS = input('Enter value of EPSILON(Accuracy of calculations): ');

% Maximum number of iterations: 
disp('-----------------------------');
maxIter = 100;
maxIter = input('Enter maximum number of iterations:  ');

err = 10; % initial value of error
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
            
            if type(i) ==  2
                %V(i) = 1i*imag(V(i)) + sqrt((abs(vTmp))^2-(imag(V(i)))^2);
                V(i) = abs(vTmp)*cos(angle(V(i))) + 1i*abs(vTmp)*sin(angle(V(i)));
            end
        end
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
disp(['Injected real power of buses are : ', num2str(abs(real(S)))])
disp(['Injected reactive power of buses are : ', num2str(abs(imag(S)))])
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
PLine = real(SLine);  %% must not be lower than power capacity of lines