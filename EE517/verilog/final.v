module final(a,b, c, out, out_bar);
	input a, b, c;
	output out, out_bar;
	and and1(w, a, b);
	and and2(z, w, b);
	or or1(x, w, c);
	or or2(y, x, w);
	xor xor1(out, y, z);
	not not1(out_bar, out);	
endmodule
