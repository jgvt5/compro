int n, m;
int n2;
ll dat[1 << 18];
int mindex[1 << 18];

void init(int size) {
	n2 = 1;
	while (n2 <= size) {
		n2 *= 2;
	}
	for (int i = 0; i < 2 * n2 - 1; i++) {
		dat[i]	= INF;
		mindex[i] = i >= n2 - 1 ? i - n2 + 1 : -1;
	}
}

void update(int i, int v) {
	int j  = i + n2 - 1;
	dat[j] = v;
	while (j > 0) {
		j = (j - 1) / 2;
		if (dat[2 * j + 1] < dat[2 * j + 2]) {
			dat[j]	= dat[2 * j + 1];
			mindex[j] = mindex[2 * j + 1];
		} else {
			dat[j]	= dat[2 * j + 2];
			mindex[j] = mindex[2 * j + 2];
		}
	}
}

int querry_index(int a, int b) {
	a += n2 - 1;
	b += n2;
	ll left = INF, right = INF;
	int ind1 = -1, ind2 = -1;
	while (a < b) {
		if ((a & 1) == 0 && left > dat[a]) {
			left = dat[a];
			ind1 = mindex[a];
		}
		if ((b & 1) == 0 && right > dat[b - 1]) {
			right = dat[b - 1];
			ind2  = mindex[b - 1];
		}
		a = a / 2;
		b = (b - 1) / 2;
	}

	return left < right ? ind1 : ind2;
}