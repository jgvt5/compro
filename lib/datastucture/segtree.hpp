#include <bits/stdc++.h>

template <class Monoid>
class SegTree {
	using OP = std::function<Monoid(Monoid, Monoid)>;

  private:
	int n;
	std::vector<Monoid> dat;
	OP op;
	Monoid e;

  public:
	SegTree(int n_, OP op, Monoid e) : op(op), e(e) {
		n = 1;
		while (n < n_) {
			n *= 2;
		}
		dat.resize(2 * n);
		for (int i = 0; i < 2 * n - 1; i++) {
			dat[i] = e;
		}
	}
	void update(int k, Monoid v) {
		k += n - 1;
		dat[k] = v;
		while (k > 0) {
			k	  = (k - 1) / 2;
			dat[k] = op(dat[2 * k + 1], dat[2 * k + 2]);
		}
	}
	Monoid query(int a, int b) const {
		Monoid left  = e;
		Monoid right = e;
		a += n - 1;
		b += n;
		while (a < b) {
			if ((a & 1) == 0) {
				left = op(left, dat[a]);
			}
			if ((b & 1) == 0) {
				right = op(dat[b - 1], right);
			}
			a = a / 2;
			b = (b - 1) / 2;
		}
		return op(left, right);
	}
};