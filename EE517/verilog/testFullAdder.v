`timescale 1ns/10ps

module testFullAdder;
	reg a, b, cin;
	wire sum, carry;
	fullAdder myFullAdder(a, b, cin, sum, carry);
	
	initial
	begin
		$dumpfile("testFullAdder.vcd");
		$dumpvars(0,testFullAdder);
		cin=0;
		a=0;
		b=1;
		#1;
		a=0;
		b=0;
		cin=1;
		#1;
		cin=0;
		b=0;
		#3;
		a=0;
		$finish;
	end

endmodule
