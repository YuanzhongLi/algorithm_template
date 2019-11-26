struct road {
	int sx;
	int add;
	int dis;
	road(int _sx, int _add, int _dis){
		sx = _sx;
		add = _add;
		dis = _dis;
	}
	bool operator < (road &r2){
		if (sx != r2.sx){
			return sx < r2.sx;
		} else {
			return add < r2.add;
		}
	}
};
