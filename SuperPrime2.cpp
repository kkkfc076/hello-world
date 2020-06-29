//��ҵ���������������¿�ܵĴ���ϸ�ڣ������ܱ������еõ���ȷ��� 
#include <iostream>
class Prime {
  public:
  	Prime():number(0) {
	}
  	Prime(int n):number(n) {
	}
	~Prime() {
	}
  	bool isPrime() { 
  	  if(number==1||number==0)
		return false;
	  for(int i=2;i<number;i++)
	  {
		if(number%i==0)
			return false;
	  }
			//2��number-1������ 
  	  return false;
	}
  private:
  	const int number;
}; 
class PrimeSet {
  public:
  	PrimeSet(int size) {
  	  //���ϵĹ���ʲô�� 
  	  N = new Prime*[size];
  	  this->size = size;
  	  index = 0;
	}
	~PrimeSet() {
  	  for (int i = 0; i < index; ++i)  //���ٶ��� 
		delete N[i]; 
	  delete[] N;
	}
	bool add(int n) {
	  if(index == size)  return false;
	  Prime *p = new Prime(n);
	  N[index] = p;
	  index += 1;
	  return true;
	}
	bool isAllPrime() {
	  for(int i = 0; i < index; i++)
	    if (!N[i]->isPrime())
	      return false;
	  return true;
	} 
  private:
  	Prime **N;
	int size, index;
};
class SuperPrime {
  public:
	SuperPrime():number(0), pset(3) {  //Ϊʲô�����У� 
 	}
  	SuperPrime(int n):number(n), pset(3) {
  	  split();  //�����ǹ������ 
	}
  	~SuperPrime() {
	}
	bool isSuperPrime() {
	//��ôʹ��pset�� 
	    Prime p(number);
	  		if (p.isPrime()&&pset.isAllPrime())
			  return true; 
	    return false;
		}
	
  private:
  	const int number;
    PrimeSet pset;
  	int size_N,N[10];
	void split() {   //�����������ģʽ 
	// number split into N
	  int temp = number;
	  for(int i=0;temp > 0;i++) {
	  	int n = temp % 10;
	  	temp /= 10;
	  	N[i]=n;}
	  	pset.add(sum());
	  	pset.add(multi());
		pset.add(squareSum());  //��ҵ����������Ϊ���󣿻��Ǻ�/��/ƽ����Ϊ���� 
	  } 
	
	int sum() {
		int sum_number=0;
		for(int i=0;i<size_N;i++)
		{
			sum_number+=N[i];
		}
	  return sum_number;
	}
	int multi() {
		int multi_number=1;
		int i;
		for(i=0;i<size_N;i++)
		{
			multi_number*=N[i];
		}
	  return multi_number;
	}
	int squareSum() {
		int square_num=0;
		for(int i=0;i<size_N;i++)
		{
			square_num+=(N[i]*N[i]);
		}
	  return square_num;
	}
 };
int main() {
    SuperPrime sp(113);
    if (sp.isSuperPrime())
        std::cout << "113 is SuperPrime" << std::endl;
    else
        std::cout << "113 is NOT SuperPrime" << std::endl;
    return 0;
}
