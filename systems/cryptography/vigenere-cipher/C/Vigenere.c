#include<stdio.h>

int main()
{
	int i;
	char plainText[100],cipherText[100],key[30], dec[100];
	int ptlen,klen;
	printf("Enter Plain Text:");
	scanf("%s",plainText);
	for(i=0;plainText[i]!='\0';++i);
	ptlen=i;
	printf("Enter Key:");
	scanf("%s",key);
	for(i=0;key[i]!='\0';++i);
	klen=i;
	cipherText[ptlen]='\0';
	for(i=0;i<ptlen;++i)
	{
		cipherText[i] = 'a'+((key[i%klen]-'a')+(plainText[i]-'a'))%26;
	}
	printf("Encrypted Cipher: %s\n",cipherText);
	dec[ptlen]='\0';
	for(i=0;i<ptlen;++i)
	{
		dec[i] = 'a'+((cipherText[i]-'a')-(key[i%klen]-'a')+26)%26;
	}
	printf("Decrypted as: %s\n",dec);
	
	
return 0;
}
