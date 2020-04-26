#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string::const_iterator State;
class ParseError {};

ll number(State &);
ll factor(State &);
ll term(State &);
ll expr(State &);

ll number(State &begin) {
	ll ret = 0;
	while (isdigit(*begin)) {
		ret *= 10;
		ret += *begin - '0';
		begin++;
	}
	return ret;
}
ll factor(State &begin) {
	if (*begin == '(') {
		begin++;
		ll ret = expr(begin);
		begin++;
		return ret;
	} else {
		return number(begin);
	}
}
ll term(State &begin) {
	ll ret = factor(begin);
	while (1) {
		if (*begin == '*') {
			begin++;
			ret *= factor(begin);
		} else if (*begin == '/') {
			begin++;
			ret /= factor(begin);
		} else {
			break;
		}
	}
	return ret;
}
ll expr(State &begin) {
	ll ret = term(begin);
	while (1) {
		if (*begin == '+') {
			begin++;
			ret += term(begin);
		} else if (*begin == '-') {
			begin++;
			ret -= term(begin);
		} else {
			break;
		}
	}
	return ret;
}