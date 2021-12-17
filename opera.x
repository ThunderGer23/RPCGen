struct EsMat{
	float prod <100>;
};

struct r_times_Mat{
	int Mat <100>;
	int Mat_size;
	float Es;
};

program OPE_PROG
{
	version OPE_VERS
	{		
		EsMat product(r_times_Mat) = 3;
	} = 1;
} = 0x23350034;
