long long  multiplyTwoLists (Node* l1, Node* l2)
{
  //Your code here
  long long int i1 = 0;
  long long int i2 = 0;
  int mod = 1000000007;
  while(l1!=NULL){
      i1 = (i1*10+l1->data)%mod;
      l1=l1->next;
  }
  while(l2!=NULL){
      i2 = (i2*10 + l2->data)%mod;
      l2=l2->next;
  }
  return (i1*i2)%mod;
}
