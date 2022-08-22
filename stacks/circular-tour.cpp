 int tour(petrolPump p[],int n)
{ 
    int deficit = 0,start = 0, c =0;
        for(int i =0 ; i < n;i++){
            c += p[i].petrol-p[i].distance;
            if(c<0){
                start = i+1;
                deficit+=c;
                c=0;
            }
        }
        return (c+deficit>0) ? start: -1;
}
