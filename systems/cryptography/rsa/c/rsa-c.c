#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ll long long int

struct publicKey{
	ll n;
	ll e;
	ll p;
	ll q;
};

ll gcd(int a, int b){
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

ll phi(int p, int q) {
	return (p-1)*(q-1);
}

ll getExponent(struct publicKey pub) {
	ll phi_n = phi(pub.p, pub.q);

	ll e = rand()%phi_n;
	ll g = gcd(e, phi_n);
	while(g != 1) { 
		e = rand()%phi_n;
		g = gcd(e, phi_n);
	}

	return e;
}

struct publicKey generatePublicKey() {
	struct publicKey pub;

	printf("\nEnter p, q: ");
	scanf("%llu%llu", &pub.p, &pub.q);

	pub.n = pub.p*pub.q;

	pub.e = getExponent(pub);

	return pub;
}

ll generatePrivateKey(struct publicKey pub) {
	ll d;
	ll phi_n = phi(pub.p, pub.q);

	for(d = 1; d < phi_n; ++d)
		if((d*pub.e)%phi_n == 1)
			break;
	return d;
}

ll encrypt(ll plaintext, struct publicKey pub) {
	ll encrypted = 1;
	int i;
	for(i = 1; i <= pub.e; ++i)
		encrypted = (encrypted*plaintext)%pub.n;
	return encrypted;
}

ll decrypt(ll ciphertext, ll d, struct publicKey pub){
	ll decrypted = 1;
	int i;
	for(i = 1; i <= d; ++i)
		decrypted = (decrypted*ciphertext) % pub.n; 
	return decrypted;
}

int main() {

	srand(time(NULL));

	//Generate data
	ll plaintext = rand()%1000;
	printf("Generated Plaintext : %llu\n", plaintext);

	//Generate public key
	struct publicKey pub = generatePublicKey();

	//printf("Exponent : %llu\n", pub.e);

	//Generate private key
	ll d = generatePrivateKey(pub);

	//printf("private key : %llu\n", d);

	//Encrypt data
	ll ciphertext = encrypt(plaintext, pub);
	printf("Encrypted message(Cipher text) : %llu\n", ciphertext);

	//Decrypt data
	ll decrypted = decrypt(ciphertext, d, pub); 

	printf("Decrypted message : %llu\n", decrypted);

}
