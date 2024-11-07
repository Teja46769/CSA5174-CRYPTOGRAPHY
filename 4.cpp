 #include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char* plaintext, char* key, char* ciphertext) {
    int textLength = strlen(plaintext);
    int keyLength = strlen(key);

    for (int i = 0, j = 0; i < textLength; i++) {
        if (isalpha(plaintext[i])) {
            char offset = isupper(plaintext[i]) ? 'A' : 'a';
            char keyOffset = isupper(key[j % keyLength]) ? 'A' : 'a';
            ciphertext[i] = ((plaintext[i] - offset) + (key[j % keyLength] - keyOffset)) % 26 + offset;
            j++;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[textLength] = '\0';
}

void decrypt(char* ciphertext, char* key, char* decryptedText) {
    int textLength = strlen(ciphertext);
    int keyLength = strlen(key);

    for (int i = 0, j = 0; i < textLength; i++) {
        if (isalpha(ciphertext[i])) {
            char offset = isupper(ciphertext[i]) ? 'A' : 'a';
            char keyOffset = isupper(key[j % keyLength]) ? 'A' : 'a';
            decryptedText[i] = ((ciphertext[i] - offset) - (key[j % keyLength] - keyOffset) + 26) % 26 + offset;
            j++;
        } else {
            decryptedText[i] = ciphertext[i];
        }
    }
    decryptedText[textLength] = '\0';
}

int main() {
    char plaintext[100], key[100], ciphertext[100], decryptedText[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = '\0';

    encrypt(plaintext, key, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);

    decrypt(ciphertext, key, decryptedText);
    printf("Decrypted text: %s\n", decryptedText);

    return 0;
}

