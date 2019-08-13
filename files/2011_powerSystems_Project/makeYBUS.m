function ybus = makeYBUS()
% 
% busNum = 3;
% %     | bus1 | bus2 |  number  |   R   |   X
% line = [ 1       2         1         0       0.4
%          1       3         1         0       0.2 
%          2       3         1         0       0.25];

% yekan 1 4 8 
busNum = 6;
%      [ bus1   bus2    number      R        X  ]
line = [ 1       4         1       0.15     0.6
         1       5         1       0.05     0.2
         2       3         2       0.05     0.2
         2       4         1       0.1      0.4
         3       5         3       0.05     0.2
         4       6         4      0.0750    0.3 ];

% yekan 0 3 7
% busNum = 6;
% line= [ 1       4         1       0.15     0.6
%         1       5         1       0.05     0.2
%         2       3         3       0.05     0.2
%         2       4         1       0.1      0.4
%         2       6         1      0.0750    0.3
%         3       5         2       0.05     0.2
%         4       6         3      0.0750    0.3];

bus1 = line(:,1);
bus2 = line(:,2);
num = line(:,3);
r = line(:,4);
x = line(:,5);
z = (r + 1i*x)./num;
y = 1./z;

branchNum = length(bus1);
ybus = zeros(busNum,busNum);

% Off-diagonal elements
for k=1:branchNum
    ybus(bus1(k),bus2(k)) = -y(k);
    ybus(bus2(k),bus1(k)) = ybus(bus1(k),bus2(k));
end

% Diagonal elements
for m=1:busNum
    for n=1:branchNum
        if bus1(n) == m || bus2(n) == m
            ybus(m,m) = ybus(m,m) + y(n);
        end
    end
end
end