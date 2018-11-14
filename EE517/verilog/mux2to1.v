module mux2to1(s,in0, in1, out);
	//identify input
	input in0, in1, s;
	//identify output
	output out;
	
	//wire or a register! Default: wire
	
	//step 1: take signal s, make it pass the 'not' gate, and produce s_bar
	//step 2: take signal s_bar, and AND it with in0
	//step 3: take and2
	
	//GATE_TYPE. Name_of_gate(OUTPUT, INPUTS)
	not inv1(s_bar, s);
	and and1(and1_o, s_bar, in0);
	and and2(and2_o, s, in1);
	or or1(out, and1_o, and2_o);
	not inv2(out_bar, out);
	
endmodule
