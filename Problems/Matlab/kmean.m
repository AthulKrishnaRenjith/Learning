addpath 'C:\Users\ACER\Documents\MATLAB\netlab3'
which kmeans

d=[1 1;2 1;3 1;5 6;6 5;6 6];
c=[2 2;3 2];

d1=d(:,1);
d2=d(:,2);

c1=c(:,1);
c2=c(:,2);

scatter(d1,d2,40,'blue','filled')
hold on
scatter(c1,c2,40,'red','filled')

options=foptions();
kmeans(c,d,options);

b=ans;
b1=b(:,1);
b2=b(:,2);

scatter(b1,b2,'green','filled')
