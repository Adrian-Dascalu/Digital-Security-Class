ap=input('ap=20 ');
fp=input('fp=800 ');
a0=input('a0=5 ');
f0=input('f0=100 ');
n=input('n=4 ');
fn=input('fn=750 ');

t=0.:0.0001:.05;

sp=ap*cos(2*pi*fp*t);
figure(1)
subplot(211)
plot(t,sp)
title('SEMNAL PURTATOR');
xlabel('Timp [s]')

p=fft(sp);
Ppp=p.*conj(p);
s=length(Ppp);
f=10000*(0:s/2-1)/s;
subplot(212)
plot(f(1:100),Ppp(1:100));
title('FUNCTIA DENS.SPECTR.-SEMNAL PURTATOR')
xlabel('Frecventa - Hz')

figure(2)
m=a0*cos(2*pi*f0*t);
subplot(211)
plot(t,m)
title('SEMNAL MODULATOR');
xlabel('Timp - [s]')

mm=fft(m);
Pmm=mm.*conj(mm);
subplot(212)
plot(f(1:100),Pmm(1:100));
title('FUNCTIA DENS. SPECTR.-SEMNAL MODULATOR')
xlabel('Frecventa - Hz')

sma=sp.*m; //semnalul modulat in amplitudine este produsul semnalului purtator cu semnalul modulator
figure(3)
subplot(211)
plot(t,sma);
title('SEMNAL MODULAT');
xlabel('Timp - [s]')

ma=fft(sma);
Pma=ma.*conj(ma);
subplot(212)
plot(f(1:100),Pma(1:100));
title('FUNCTIA DENS. SPECTR.-SEMNAL MODULAT')
xlabel('Frecventa - Hz')

eta=n*cos(2*pi*fn*t);
figure(4)
subplot(211)
plot(t,eta)
title('SEMNAL PERTURBATOR')
xlabel('timp-[s]')

ee=fft(eta);
Pee=ee.*conj(ee);
subplot(212)
plot(f(1:100),Pee(1:100));
title('FUNCTIA DENS. SPECTR.-SEMNAL PERTURBATOR')
xlabel('Frecventa - Hz')

sr=sma+eta;
figure(5)
subplot(211)
plot(t,sr)
title('SEMNAL RECEPTIONAT')
xlabel('timp-[s]')

r=fft(sr);
Prr=r.*conj(r);
subplot(212)
plot(f(1:100),Prr(1:100));
title('FUNCTIA DENS. SPECTR.-SEMNAL RECEPTIONAT')
xlabel('Frecventa - Hz')

smap=sr+sp;
smapp=smap.*smap;
figure(6)
subplot(211)
plot(t,smapp)
title('smapp^2')

map=fft(smapp);
Pmap=map.*conj(map);
subplot(212)
plot(f(1:100),Pmap(1:100));
title('FUNCTIA DENS. SPECTR.-SEMNAL SMAP^2')
xlabel('Frecventa - Hz')

tj=1/(4*pi*f0);
ts=1/(4*pi*(fp-f0));
nums=[ts 0];
dens=[ts 1];
numj=[1];
denj=[tj 1];
w=logspace(-1,5);
[mags,phases]=bode(nums,dens,w);
ys=log10(mags);
figure(7)
subplot(211)
semilogx(w,ys)
grid
title('CARACT. AMPLIT.-FRECV. FTS')
ylabel('dB')
subplot(212)
semilogx(w,phases)
grid
title('CARACT. FAZA-FRECV. FTS')
ylabel('rad')

[magj,phasej]=bode(numj,denj,w);
yj=log10(magj);
figure(8)
subplot(211)
semilogx(w,yj)
grid
title('CARACT. AMPLIT.-FRECV. FTJ')
ylabel('dB')
subplot(212)
semilogx(w,phasej)
grid
title('CARACT. FAZA-FRECV. FTJ')
ylabel('rad')

b=lsim(nums,dens,smapp,t);
c=lsim(numj,denj,smapp,t);
figure(9)
subplot(211)
plot(t,b)
title('SEMNAL B DUPA FTS')
xlabel('timp-[s]')
subplot(212)
plot(t,c)
title('SEMNAL C DUPA FTJ')
title('timp-[s]')

mb=fft(b); //transformata Fourier a semnalului b obtinut in urma filtrarii
Pmb=mb.*conj(mb); //functia densitatii spectrale a semnalului b
s=length(Pmb);
figure(10)
subplot(211)
plot(f(1:100),Pmb(1:100));
title('FUNCTIA DENS. SPECTR.-SEMNAL B')
xlabel('Frecventa - Hz')

mc=fft(c); 
Pmc=mc.*conj(mc);s=length(Pmc); 
subplot(212)
plot(f(1:100),Pmc(1:100));
title('FUNCTIA DENS. SPECTR.-SEMNAL C')
xlabel('Frecventa - Hz')

d(1)=1;
for i=2:length(t),
d(i)=b(i)./c(i);
end
spd=sqrt((d+1)/2).*sign(sp);

u=spd;

tjf=1/(2*pi*fp);
numf=[1];
denf=[tjf 1];
spf=lsim(numf,denf,u,t);

sspf=fft(spf);
Pspf=sspf.*conj(sspf);
figure(11)
plot(f(1:100),Pspf(1:100));
title('FUNCTIA DENS. SPECTR.-SEMN. PURT. RECONST.')
xlabel('Frecventa - Hz')

figure(12)
subplot(211)
plot(t,spf)
title('SEMNAL PURTATOR RECONSTITUIT');
xlabel('timp-[s]')
subplot(212)
plot(t,sp)
title('SEMNAL PURTATOR REAL')
xlabel('timp-[s]')