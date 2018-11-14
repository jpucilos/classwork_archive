`timescale 1ns/10ps

module testFinal;
	reg a, b, c;
	wire out, out_bar;
	final myFinal(a, b, c, out, out_bar);
	
	initial
	begin
		$dumpfile("testFinal.vcd");
		$dumpvars(0,testFinal);
		c=0;
		a=0;
		b=1;
		#1;
		a=0;
		b=0;
		c=1;
		#1;
		c=1;
		b=1;
		a=1;
		#1;
		c=0;
		b=0;
		a=0;
		#1;
		c=1;
		b=0;
		a=1;
		#1;		

		$finish;
	end
endmodule
