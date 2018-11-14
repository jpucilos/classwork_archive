module halfAdder(a, b, carry, sum);
	input a, b;
	output carry, sum;
	xor xor1(sum, a, b);
	and and1(carry, a, b);
endmodule
