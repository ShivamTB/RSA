// ECE4122/6122 RSA Encryption/Decryption assignment
// Fall Semester 2015

#include <iostream>
#include "RSA_Algorithm.h"

using namespace std;

int main()
{
    // Instantiate the one and only RSA_Algorithm object
    RSA_Algorithm RSA;
    
    // Loop from sz = 32 to 1024 inclusive
    // for each size choose 10 different key pairs
    // For each key pair choose 10 differnt plaintext
    // messages making sure it is smaller than n.
    // If not smaller then n then choose another
    // For eacm message encrypt it using the public key (n,e).
    // After encryption, decrypt the ciphertext using the private
    // key (n,d) and verify it matches the original message.
    
    for(int sz = 32; sz <= 1024; sz = sz * 2)
    {
        
        for (int i = 0; i<10; i++){
            RSA.GenerateRandomKeyPair(sz);
            
            RSA.PrintNDE();
            mpz_class M;
            for(int j = 0; j < 10; j++)
            {
                bool flag = true;
                while(flag){
                    M = RSA.rng.get_z_bits(sz);
                    if (M<RSA.n){
                        flag = false;
                    }
                }
                
                
                RSA.PrintM(M);
                
                
                mpz_class C = RSA.Encrypt(M);
                
                RSA.PrintC(C);
                
                mpz_class T = RSA.Decrypt(C);
                
                
                //   if(T == M)
                //     cout << "// RSA Encryption successful." << endl;
                //  else
                //    cout << "// RSA Encryption not successful." << endl;
                
            }
        }
    }
}

