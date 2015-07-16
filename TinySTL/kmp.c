void GetNext(char*key,int *next){
	int length=strlen(key);
	int i=0;
	int k=-1;
	next[0]=-1;
	while(i<length-1){//因为
		if(k==-1||key[k]==key[i])
			{
			k++;i++;
			next[i]=k;
			}
		else
			{
			k=next[k];
			}
	}
}
int  KmpSerach(char* dat,char*key){
	int len_dat=strlen(dat);
	int len_key=strlen(key);
	int *next=(int*)malloc((len_key+1)*sizeof(int));
	int i=0,j=0;
	if(!next){
		exit(-1);
	}
	GetNext(key,next);
	while(i<len_dat&&j<len_key){
		if(j==-1||dat[i]==key[j]){
			i++;j++;
		}
		else{
			j=next[j];
		}
	}
	return j==len_key?i-j:-1;
}
