/** Somador de numeros*/
#include <stdio.h>

struct numero{
    char c[300];
    int local,ponto,fat;
};

struct numero reset_num(struct numero num){
    int i=0;
    while(i<num.local){
	num.c[i]='0';
	i++;
    }
    num.local=0;
    num.ponto=0;
    num.fat=0;
    return num;
}

float soma(float sum, struct numero num){
    float parcela;
    if(num.local!=0){
        sscanf(num.c,"%f",&parcela);
        sum = sum + parcela;
    }
    return sum;
}

float fatorial(struct numero num){
    float fat, i, n;
    i=1;
    fat=1;
    sscanf(num.c,"%f",&n);
    while ( i<=n){
        fat=i*fat;
        i++;
    }
    return fat;
}

int main(){
    char c;
    float s,f;
    struct numero num;
    num=reset_num(num);
    
    while((c = getchar()) != '\n') {
        switch (c) {
            case'0': case '1': case'2': case '3': case'4': case'5': case'6': case'7': case'8': case'9':
                /**verifica se já não teve um '!' indicando fatorial**/
                if(num.fat==0){
                    num.c[num.local] = c;
                    num.local++;
                    break;
                }
                num = reset_num(num);
                break;
            case '.':
                /**verifica se já não teve um '!' indicando fatorial ou outro '.'**/
                if(num.ponto==0 && num.fat==0){
                    num.c[num.local] = c;
                    num.local++;
                    num.ponto++;
                    break;
                }
                num = reset_num(num);
                break;
            case '!':
                if(num.ponto==0 && num.fat==0){
                    num.fat++;
                    break ;
                }
                num = reset_num(num);
                break;
            case ' ': case '\n':
                /**verifica se o num.c tem algo a acrescentar na soma*/
                if(num.local!=0){
                    if(num.fat==0){
                        s=soma(s,num);
			num = reset_num(num);
                        break;
                    }
                    else{
			f=fatorial(num);
                    	s=s+f;
		    	num = reset_num(num);
                    	break;
		    }
                }
		num = reset_num(num);
                break;
            default: 
                num = reset_num(num);
                break;
                
        }
    }
     /**verifica se o string em num.c ja foi computado**/
     if(num.local!=0){
     	if(num.fat==0){
        	s=soma(s,num);
        }
        else {
		f=fatorial(num);
	        s=s+f;
        }
     }
	printf("%.2f\n", s);
     return 0;
}

