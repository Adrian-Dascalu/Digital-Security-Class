ap=input('ap=20   ');
fp=input('fp=400   ');
a0=input('a0=5  ');
f0=input('f0=100    ');
n=input('n=4   ');
fn=input('fn=300   ');

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
plot(f(1:30),Ppp(1:30));
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
plot(f(1:30),Pmm(1:30));
title('FUNCTIA DENS. SPECTR.-SEMNAL MODULATOR')
xlabel('Frecventa - Hz')

sma=(ap+m).*cos(2*pi*fp*t); //semnalul modulat in amplitudine este suma amplitudinii semnalului purtator cu semnalul modulator
figure(3)
subplot(211)
plot(t,sma);
title('SEMNAL MODULAT');
xlabel('Timp - [s]')

ma=fft(sma);
Pma=ma.*conj(ma);
subplot(212)
plot(f(1:30),Pma(1:30));
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
plot(f(1:30),Pee(1:30));
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
plot(f(1:30),Prr(1:30));
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
plot(f(1:30),Pmap(1:30));
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
subplot(212)
plot(t,c)
title('SEMNAL C DUPA FTJ')

sb=fft(b);
Pbb=sb.*conj(sb);
figure(10)
subplot(211)
plot(f(1:60),Pbb(1:60));
title('FUNCTIA DENS. SPECTR.-SEMNAL B')
xlabel('Frecventa - Hz')

sc=fft(c);
Pcc=sc.*conj(sc);
subplot(212)
plot(f(1:60),Pcc(1:60));
title('FUNCTIA DENS. SPECTR.-SEMNAL C')
xlabel('Frecventa - Hz')

d(1)=1;
for i=2:length(t),
   d(i)=b(i)./c(i);
end
spd=sqrt((d+1.2)/2).*sign(sp);

u=spd;

tjf=1/(2*pi*fp);
numf=[1];
denf=[tjf 1];
spf=lsim(numf,denf,u,t);

sspf=fft(spf);
Pspf=sspf.*conj(sspf);
figure(11)
plot(f(1:30),Pspf(1:30));
title('FUNCTIA DENS. SPECTR.-SEMN. PURT. RECONST.')
xlabel('Frecventa - Hz')

figure(12)
subplot(211)
plot(t,spf)
title('SEMNAL PURTATOR RECONSTITUIT');
subplot(212)
plot(t,sp)
title('SEMNAL PURTATOR REAL')