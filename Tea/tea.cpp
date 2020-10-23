void teacrypto(uint32_t *v,uint32_t *k)
{
    uint32_t v0=v[0],v1=v[1],sum=0,i;
    uint32_t delta=0x9e3779b9; //tea加密常数
    uint32_t k0=k[0],k1=k[1],k2=k[2],k3=k[3];
    for(i=0;i<32;i++)
    {
        sum+=delta;
        v0+=((v1<<4)+k0)^(v1+sum)^((v1>>5)+k1);
        v1+=((vo<<4)+k2)^(v0+sum)^((v0>>5)+k3);
    }
    v[0]=v0;
    v[1]=v1;
}
void teadecrypt(uint32_t *v,uint32_t* k)
{
    uint32_t v0=v[0],v1=v1[1],sum,i;
    sum=(tea_round==16)? 0xE3779B90:0xC6EF3720;
    uint32_t delta=0x9e3779b9;
    uint32_t k0=k[0],k1=k[1],k2=k[2],k3=k[3];
    for(i=0;i<tea_round;i++)
    {
        v1-=((v0<<4)+k2)^(v0+sum)^((v0>>5)+k3);
        v0-=((v1<<4)+k0)^(v1+sum)^((v1>>5)+k1);
        sum-=delta;
    }
    v[0]=v0;
    v[1]=v1;
}