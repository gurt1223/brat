% design multisine using SIDPAC
format shortg
format compact
close all
clear
clc
addpath(genpath("C:\Users\17036\Documents\Fall 24\Masters\SIDPAC"))
LaTeXify;

% duration (s)
T = 30;
Tstr = num2str(T);

% number of inputs
ni_serv = 6;
ni_prop = 1;
ni = ni_serv + ni_prop;
nistr = num2str(ni);
labels = {'$\delta a_\mathrm{L}$','$\delta a_\mathrm{R}$','$\delta e$',...
          '$\delta r$','$\delta f_\mathrm{L}$','$\delta f_\mathrm{R}$',...
          '$\Omega$'};

% time step
dt = 0.01;
fs = 1/dt; % Hz
fs_str = num2str(fs);

% minimum frequency
fmin = 0.05;
fmin_str = replace(num2str(fmin),'.','');

% servo signal frequencies
fmax = 2;
fmax_str = replace(num2str(fmax),'.','');
frange_servo = fmax - fmin;

% motor signal frequencies
fmax_prop = 0.8;
fmax_prop_str = replace(num2str(fmax_prop),'.','');
frange_prop = fmax_prop - fmin;

% amplitude of inputs
amp = ones(ni,1);

% frequency spacing
df = 1/T;
dfstp = 1;
freq = fmin:df:fmax;

% Below the max prop frequency, alternate between prop and servo
freq_low = freq(freq<=fmax_prop);
freq_prop = freq_low(1:ni_prop+1:end);
freq_serv = [freq_low(ni_prop+1:ni_prop+1:end) freq(freq>fmax_prop)];

% Reshape and pad with zeros
nf_prop = floor(length(freq_prop)/ni_prop)*ni_prop;
nf_serv = floor(length(freq_serv)/ni_serv)*ni_serv;
fu_prop = [reshape(freq_prop(1:nf_prop),ni_prop,[])';
           zeros(max([nf_prop/ni_prop,nf_serv/ni_serv])-nf_prop/ni_prop,ni_prop)];
fu_serv = [reshape(freq_serv(1:nf_serv),ni_serv,[])'; 
           zeros(max([nf_prop/ni_prop,nf_serv/ni_serv])-nf_serv/ni_serv,ni_serv)];

% Final list of frequencies
fu = [fu_serv fu_prop];

% Design the orthogonal optimized multi-sine inputs.
[u,t,pf,f,M,ph,pwr,ph0] = mkmsswp(amp,fmin,fmax,dt,T,ni,fu);

%%
% save the multisine time data
filename = ['ms_aeroprop_' num2str(ni_serv) 's' num2str(ni_prop) 'p' 'T' Tstr '_f' fmin_str '-' fmax_prop_str '-' fmax_str '_' fs_str 'hz']
save(['../ExcitationSignals/' filename '.mat'],'t','u','pf','f','M','ph','fmin','fmax','fmax_prop','fu','T','fs','pwr')

% also save as csv with t column in hundreths of a second
writematrix([t*100,u],['../ExcitationSignals/' filename '.csv'])

%% Plot

% Plot the multisine power fractions
colors = ["#0072BD","#D95319","#EDB120","#7E2F8E","#77AC30","#4DBEEE","#A2142F"];
figSize = [6 3.5];
fig = figure;
fig.Units = 'inches';
fig.Position(3:4) = figSize;
fig.PaperSize = figSize;
hold on
width = 0.02;
for ii = 1:ni_serv
    for jj = 1:floor(nf_serv/ni_serv)
        if jj == 1
            extraArgs = {'DisplayName',labels{ii}};
        else
            extraArgs = {'HandleVisibility','off'};
        end
        bar(f(jj,ii),pwr(jj,ii),width,'FaceColor',colors(ii),'EdgeColor','none',extraArgs{:})
    end
end
for ii = ni_serv+1:ni
    for jj = 1:floor(nf_prop/ni_prop)
        if jj == 1
            extraArgs = {'DisplayName',labels{ii}};
        else
            extraArgs = {'HandleVisibility','off'};
        end
        bar(f(jj,ii),pwr(jj,ii),width,'FaceColor',colors(ii),'EdgeColor','none',extraArgs{:})
    end 
end
hold off
grid on
grid minor
box on
xlabel('Frequency [Hz]')
ylabel('Normalized Power Spectral Density')
legend('Orientation','horizontal','Location','northoutside')
ax = gca;
ax.FontSize = 10;
ax.FontName = 'Times';
ax.XColor = 'k';
ax.YColor = 'k';
exportgraphics(fig,['./Figures/' filename '_PSD.pdf'],'ContentType','vector')
exportgraphics(fig,['./Figures/' filename '_PSD.png'],'Resolution',600)
savefig(fig,['../ExcitationSignals/' filename '_PSD'],'compact');

% plot the time domain results
figSize = [7 3.5];
fig = figure;
fig.Units = 'inches';
fig.Position(3:4) = figSize;
fig.PaperSize = figSize;
tiledlayout(ni,1,'TileSpacing','tight')
for ii = 1:ni
    nexttile
    plot(t,u(:,ii),'Color',colors(ii),'LineWidth',1.5)
    % ylabel(['$u_' num2str(ii) '$'])
    ylabel(labels{ii})
    ylim([-1.5 1.5])
    if ii < ni
        set(gca,'xtick',[]);
    end
    box on
end
text(-4,4,'Normalized Input Signal','Rotation',90)
xlabel('Time [s]')
ax = gca;
ax.FontSize = 10;
ax.FontName = 'Times';
ax.XColor = 'k';
ax.YColor = 'k';
exportgraphics(fig,['./Figures/' filename '_Time.pdf'],'ContentType','vector')
exportgraphics(fig,['./Figures/' filename '_Time.png'],'Resolution',600)
savefig(fig,['../ExcitationSignals/' filename '_Time'],'compact');

% plot the correlation
figSize = [5.6 4.8];
fig = figure;
fig.Units = 'inches';
fig.Position(3:4) = figSize;
fig.PaperSize = figSize;
X = corrcoef(u);
tiledlayout(ni,ni,"TileSpacing","none")
for ii = 1:ni
    for jj = 1:ni
        nexttile
        if ii == jj
            text(0.15,0,labels{ii},"FontSize",10);
            axis([-0.1 0.5 -0.3 0.3])
        elseif ii > jj
            text(0,0,sprintf('%+0.4f',X(ii,jj)),"FontSize",10);
            axis([-0.05 0.5 -0.3 0.35])
        else
            plot(u(:,ii),u(:,jj),'.k','MarkerSize',1);
        end
        ax = gca;
        ax.XTick = {}; ax.YTick = {};
        box on
    end
end
exportgraphics(fig,['./Figures/' filename '_Corr.png'],'Resolution',600)
savefig(fig,['../ExcitationSignals/' filename '_Corr'],'compact');


