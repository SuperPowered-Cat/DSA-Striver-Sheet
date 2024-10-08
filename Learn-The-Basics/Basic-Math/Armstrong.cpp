int order(int x) {
	int n = 0;
	while (x) {
		n++;
		x=x/10;
	}
	return n;
}


bool checkArmstrong(int n){
	int size = order(n);
	int temp = n, sum = 0;
	while (temp) {
		int rem = temp%10;
		sum +=pow(rem,size);
		temp=temp/10;
	}

	return (sum == n);
}

