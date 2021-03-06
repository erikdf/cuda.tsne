/*
*
* Copyright (c) 2014, Laurens van der Maaten (Delft University of Technology)
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* 1. Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
* 2. Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the distribution.
* 3. All advertising materials mentioning features or use of this software
*    must display the following acknowledgement:
*    This product includes software developed by the Delft University of Technology.
* 4. Neither the name of the Delft University of Technology nor the names of
*    its contributors may be used to endorse or promote products derived from
*    this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY LAURENS VAN DER MAATEN ''AS IS'' AND ANY EXPRESS
* OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
* OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO
* EVENT SHALL LAURENS VAN DER MAATEN BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
* SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
* IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
* OF SUCH DAMAGE.
*
*/


#ifndef TSNE_H
#define TSNE_H


// Define strucutre for holding index flolat values
typedef struct {
	int index;
	float value;
} IndexedFloat;

static inline double t_sign(double x) { return (x == .0 ? .0 : (x < .0 ? -1.0 : 1.0)); }

int compareIndexedFloat(const void* elem1, const void* elem2);

class TSNE
{
public:
	void run(double* sorted_distances, int* sorted_indices, int N, int no_dims, int K,
		int perplexity, double theta, double eta, double exageration, int iterations, int verbose, double* Y);
	void symmetrizeMatrix(int** row_P, int** col_P, double** val_P, int N); // should be static!
	void zeroMean(double* X, int N, int D);
	void normalize(double* X, int N, int D);

private:
	void computeGradient(int* inp_row_P, int* inp_col_P, double* inp_val_P, double* Y, int N, int D, double* dC, double theta);
	double evaluateError(int* row_P, int* col_P, double* val_P, double* Y, int N, int D, double theta);
	double randn();
	void computeGaussianPerplexity(double* sorted_distances, int* sorted_indices, int N, int D, double perplexity, int** _row_P, int** _col_P, double** _val_P);

};

#endif
