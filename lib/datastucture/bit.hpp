template <class Abel> class BIT {
	using OP = std::function<Abel(Abel, Abel)>;

  private:
	int n;
	std::vector<Abel> dat;
	OP op;
	Abel e;

  public:
	BIT(int n, OP op, Abel e = 0) : n(n), op(op), e(e) {
		dat.resize(n + 1);
		for (int i = 0; i <= n; ++i) {
			dat[i] = e;
		}
	}
	void add(int k, Abel val) {
		while (k <= n) {
			dat[k] = op(val, dat[k]);
			k += k & -k;
		}
	}
	Abel acum(int k) {
		Abel sum = e;
		while (k > 0) {
			sum = op(sum, dat[k]);
			k -= k & -k;
		}
		return sum;
	}
};