#include <stdarg.h>
#include <unistd.h>
int ft_printf(const char *f,...){va_list a;int c=0;va_start(a,f);while(*f){if(*f=='%'){f++;if(*f=='s'){char *s=va_arg(a,char*);int l=0;if(!s)s="(null)";while(s[l])l++;c+=write(1,s,l);}else if(*f=='d'){int n=va_arg(a,int);char b[11];char *p=b+10;if(n==0)c+=write(1,"0",1);else{if(n== -2147483648)c+=write(1,"-2147483648",11);else{if(n<0){c+=write(1,"-",1);n=-n;}*p='\0';do{*--p=(n%10)+'0';n/=10;}while(n>0);c+=write(1,p,b+10-p);}}}else if(*f=='x'){unsigned int n=va_arg(a,unsigned int);char h[9];char *p=h+8;char *d="0123456789abcdef";*p='\0';if(n==0)c+=write(1,"0",1);else{do{*--p=d[n%16];n/=16;}while(n>0);c+=write(1,p,h+8-p);}}}else c+=write(1,f,1);f++;}va_end(a);return c;}
