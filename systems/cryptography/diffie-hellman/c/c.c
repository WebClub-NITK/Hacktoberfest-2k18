#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#include<math.h>
#include<time.h>


int is_prime(int);
long long int get_input();
long long int powm(long long int, long long int, long long int);
int is_g_safe(long long int, long long int);
int get_rand_num(int);

int main(){
    long long int g, n, a, b, p, g_a, g_b, g_ab_aclie, g_ab_bob;
    srand((unsigned)time(NULL));

    while(1){
        printf("input p:\n");
        p = get_input();
        if(is_prime(p)){
            break;
        }
        printf("\np is not prime\n");
    }
    while(1){
        printf("input g:\n");
        g = get_input();
        if(is_g_safe(g,p)){
            break;
        }
        printf("\ng is not safe\n");
    }

    a = get_rand_num(10);
    printf("Alice choose: %lld\n", a);
    b = get_rand_num(10);
    printf("Bob choose: %lld\n", b);

    // Alice compute g^a mod p
    g_a = powm(g, a, p);

    // Bob compute g^b mod p
    g_b = powm(g, b, p);

    // (exchange g^a <-> g^b)

    // Alice compute g^(ab)
    g_ab_aclie = powm(g_b, a, p);

    // Bob compute g^(ab)
    g_ab_bob = powm(g_a, b, p);

    if(g_ab_aclie==g_ab_bob){
        printf("success!\n");
    }else{
        printf("failed\n");
    }
    printf("Alice side: %lld\n", g_ab_aclie);
    printf("Bob side: %lld\n", g_ab_bob);

    return 0;
}

int get_rand_num(int limit){
    return rand()%limit+1;
}

long long int get_input(){
    char s[100];
    long long int t;
    char *endptr;

    fgets(s, 100, stdin);
    t = strtol(s, &endptr, 10);
    if (*endptr != '\n' || (t < LONG_LONG_MIN || LONG_LONG_MAX < t)){
        printf("you input invalid value\n");
        exit(1);
    }
    return t;
}

long long int powm(long long int base, long long int exp, long long int mod){
    long long int i = 1,ret = base;
    for(i;i<exp;++i){
        ret*=base;
        ret%=mod;
    }
    return ret;
}

int cmp_long_long_int(long long*a,long long*b){
    unsigned long long v=*b-*a;
    return v?(v>>63<<1)-1:0;
}

int is_g_safe(long long int g, long long int p){
    long long int i=1, g_i=g, q=(long long int)((p-1)/2);
    long long int *chk_list;
    if(is_prime(g)){
        return 1;
    }
    chk_list = (long long int*)malloc((q)*sizeof(long long int));
    chk_list[0] = g_i;
    // check g^i !≡ 1 mod p
    for(i;i<q;++i){
        g_i*=g;
        g_i%=p;
        chk_list[i] = g_i;
    }
    qsort(chk_list, q, sizeof(long long int), cmp_long_long_int);
    for(i=0;i<q;++i){
        if(1<chk_list[i]){
            break;
        }
        if(1==chk_list[i]){
            return 0;
        }
    }
    return 1;
}

int is_prime(int p){
    int i,n=0;
    for(i=2;i<(int)sqrt(p)+1;++i){
        if(0.0==p%i){
            return 0;
        }
    }
    return 1;
}
