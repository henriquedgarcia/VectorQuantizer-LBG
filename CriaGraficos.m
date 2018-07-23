clc
clear all
close all

% x = csvread('saida.cvs',0,0);
load ('saida.cvs', '-ascii')


figure1 = figure;
axes1 = axes('Parent',figure1);
box(axes1,'on');
hold(axes1,'all');
% 
% plot(saida((1+81*0):(81+81*0),3),saida((1+81*0):(81+81*0),4),'o','LineStyle','none','DisplayName','2x1', ...
%      saida((1+81*1):(81+81*1),3),saida((1+81*1):(81+81*1),4),'+','LineStyle','none','DisplayName','2x2', ...
%      saida((1+81*2):(81+81*2),3),saida((1+81*2):(81+81*2),4),'.','LineStyle','none','DisplayName','2x4', ...
%      saida((1+81*3):(81+81*3),3),saida((1+81*3):(81+81*3),4),'x','LineStyle','none','DisplayName','4x2', ...
%      saida((1+81*4):(81+81*4),3),saida((1+81*4):(81+81*4),4),'s','LineStyle','none','DisplayName','4x4' ...
%      ); 
X1 = saida((1+81*0):(81+81*0),3);
X2 = saida((1+81*1):(81+81*1),3);
X3 = saida((1+81*2):(81+81*2),3);
X4 = saida((1+81*3):(81+81*3),3);
X5 = saida((1+81*4):(81+81*4),3);
Y1 = saida((1+81*0):(81+81*0),4);
Y2 = saida((1+81*1):(81+81*1),4);
Y3 = saida((1+81*2):(81+81*2),4);
Y4 = saida((1+81*3):(81+81*3),4);
Y5 = saida((1+81*4):(81+81*4),4);

plot(X1,Y1,'Parent',axes1,'Marker','o','LineStyle','none',...
    'DisplayName','2x1');
plot(X2,Y2,'Parent',axes1,'Marker','s','LineStyle','none',...
    'DisplayName','2x2');
plot(X3,Y3,'Parent',axes1,'Marker','.','LineStyle','none',...
    'DisplayName','2x4');
plot(X4,Y4,'Parent',axes1,'Marker','+','LineStyle','none',...
    'DisplayName','4x2');
plot(X5,Y5,'Parent',axes1,'Marker','x','LineStyle','none',...
    'DisplayName','4x4');
 
xlabel({'Taxa (bytes)'});
ylabel({'Distorção (MSE)'});
title({'Taxa x Distorção'});
legend(axes1,'show');