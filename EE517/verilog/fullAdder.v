module fullAdder(a,b, cin, sum, carry);
	input a, b, cin;
	output sum, carry;
	xor xor1(xor1, a, b);
	xor xor2(sum, xor1, cin);
	and and1(or1, cin, xor1);
	and and2(or2, a,b);
	or or1(carry, or1, or2);	
endmodule
