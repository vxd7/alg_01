#include<stdio.h>
int main() {
char q=34;
char nl=10;
char sl=92;
char qs[]="char q=34;\nchar nl=10;\nchar sl=92;\nchar qs[]=";
char h[]="#include<stdio.h>\nint main() {\n";
char hs[]="char h[]=char hs[]=";
printf("%s%s",h,qs);
printf("%c%.10s%c%c%.11s%c%c%.11s%c%c%.11s%c%c%c",q,qs,sl,110,qs+11,sl,110,qs+23,sl,110,qs+35,q,59,nl);
printf("%.9s%c%.17s%c%c%.12s%c%c%c%c%c%.10s%c%s%c%c%c",hs,q,h,sl,110,h+18,sl,110,q,59,nl,hs+9,q,hs,q,59,nl);
char pf[]="printf(%s%s,h,qs);printf(%c%.10s%c%c%.11s%c%c%.11s%c%c%.11s%c%c%c,q,qs,sl,110,qs+11,sl,110,qs+23,sl,110,qs+35,q,59,nl);printf(%.9s%c%.17s%c%c%.12s%c%c%c%c%c%.10s%c%s%c%c%c,hs,q,h,sl,110,h+18,sl,110,q,59,nl,hs+9,q,hs,q,59,nl);char pf[]=printf(%.7s%c%.4s%c%.7s%c%.7s%c%.40s%c%.54s%c%.7s%c%.45s%c%.54s%c%.10s%c%s%c%c%c%.7s%c%.91s%c%s%c},pf,q,pf+7,q,pf+11,nl,pf+18,q,pf+25,q,pf+65,nl,pf+119,q,pf+126,q,pf+171,nl,pf+225,q,pf,q,59,nl,pf+235,q,pf+242,q,pf+333,nl);";
printf("%.7s%c%.4s%c%.7s%c%.7s%c%.40s%c%.54s%c%.7s%c%.45s%c%.54s%c%.10s%c%s%c%c%c%.7s%c%.91s%c%s%c}",pf,q,pf+7,q,pf+11,nl,pf+18,q,pf+25,q,pf+65,nl,pf+119,q,pf+126,q,pf+171,nl,pf+225,q,pf,q,59,nl,pf+235,q,pf+242,q,pf+333,nl);
}
