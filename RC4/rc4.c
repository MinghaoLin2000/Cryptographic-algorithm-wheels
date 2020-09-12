#include<stdio.h>
#include<random>
#include<string.h>
#define MAX 65534
using namespace std;
int S[256];//S向量
char T[256];//T向量
int Key[256];//随机生成密钥
char PlainText[MAX]; //原文
char CryptoText[MAX];//密文
const char *WordList="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
//1.初始化S向量
void init_S()
{
    for(int i=0;i<256;i++)
    {
        S[i]=i;
    }

}
//2.通过key密钥初始化T向量
void init_key()
{
    int index;
    int index;
    srand(time(NULL));  //根据当前时间，作为种子
    int keylen = int(double(random())/double(RAND_MAX)*256);    //随机获取一个密钥的长度
    for(int i = 0; i < keylen; i++){
        index = int(double(random())/double(RAND_MAX)*63);  //生产密钥数组
        Key[i] = WordList[index];
    }
    //初始化T向量
    for(int i=0;i<256;i++)
    {
        T[i]=Key[i%keylen];
    }
}
//3.打乱S盒子向量
void permute_S()
{
    //置换S向量
    int temp;
    int j=0;
    for(int i=0;i<256;i++)
    {
        j=(j+S[i]+T[i])%256;
        temp=S[j];
        S[j]=S[i];
        S[i]=temp;
    }

}
//4.生成密钥流
void create_key_stream(char *text,int textLength)
{
    int i,j;
    int temp,t,k;
    int index=0;
    i=j=0;
    while(textLength--)
    {
        i=(i+1)%256;
        j=(j+S[i])%256;
        temp=S[i];
        S[i]=S[j];
        S[j]=temp;
        t=(S[i]+S[j])%256;
        KeyStream[index++]=S[t];

    }

}
int main()
}
    char *text; //手动输入或者键盘输入
     int textLength=strlen(text);
     init_S();
     init_key();
     permute_S();
     create_key_stream(text,textLength);
    int plain_word;
    printf("加密");
    for(int i=0;i<textLength;i++)
    {
        CryptoText[i]=char(KeyStream[i]^text[i]);//加密

    }
    CryptoText[textLength]="\0";
    printf("%s",CryptoText);
    printf("解密");
    for(int i=0;i<textLength;i++)
    {
        PlainText[i]=char(KeyStream[i]^CryptoText[i]);

    }
    PlainText[textLength]="\0";
    printf("%s",PlainText);
}
