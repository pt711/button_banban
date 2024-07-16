#ifndef APPLICATION_USER_GUI_POS_H_
#define APPLICATION_USER_GUI_POS_H_

class Position
{
public:
	int size;
	int pos_x;
	int pos_y;
	int num_x;
	int num_y;

	// 初期位置(リセット用)
	int num_x_start;
	int num_y_start;

	// 障害物マップ
	int blocker_map[10][6] = {};

	// 全部0位置初期化
	Position();

	// flag=1(デフォルト)ならpos指定の初期化、flag=2ならnum指定の初期化
	Position(int x_new, int y_new, int size_new = 80, int flag = 1)
	{
		size = size_new;
		if(flag == 1)
		{
			set_pos(x_new, y_new);
		}
		else if(flag == 2)
		{
			set_num(x_new, y_new);
		}

		num_x_start = num_x;
		num_y_start = num_y;
	}

	// リセット
	void retry()
	{
		num_x = num_x_start;
		num_y = num_y_start;
		set_num(num_x, num_y);
	}

	// 障害物マップ更新
	void update_map(int b_pos_x_new, int b_pos_y_new, int type)
	{
		int b_num_x_new = pos2num(b_pos_x_new);
		int b_num_y_new = pos2num(b_pos_y_new);
		blocker_map[b_num_x_new][b_num_y_new] = type;
	}

	// 移動可否チェック
	int check_move(int num_x_new, int num_y_new)
	{
		// 領域外チェック
		if(num_x_new < 0 || num_y_new < 0 || num_x_new > 9 || num_y_new > 5) {
			return 1;
		}

		// ブロックチェック
		else if(blocker_map[num_x_new][num_y_new] == 1) {
			return 1;
		}

		// 壁チェック
		// 上移動
		else if(blocker_map[num_x_new][num_y_new] == 2 && num_y == num_y_new+1) {
			return 1;
		}
		// 下移動
		else if(blocker_map[num_x][num_y] == 2 && num_y == num_y_new-1) {
			return 1;
		}
		// 左移動
		else if(blocker_map[num_x_new][num_y_new] == 3 && num_x == num_x_new+1) {
			return 1;
		}
		// 右移動
		else if(blocker_map[num_x][num_y] == 3 && num_x == num_x_new-1) {
			return 1;
		}

		// ゴール
		else if(blocker_map[num_x_new][num_y_new] == 9) {
			return 9;
		}


		return 0;
	}

	// pos指定の座標アップデート
	void set_pos(int pos_x_new, int pos_y_new)
	{
		int num_x_new = pos2num(pos_x_new);
		int num_y_new = pos2num(pos_y_new);

		pos_x = pos_x_new;
		pos_y = pos_y_new;
		num_x = num_x_new;
		num_y = num_y_new;
	}

	// num指定の座標アップデート
	void set_num(int num_x_new, int num_y_new)
	{
		int pos_x_new = num2pos(num_x_new);
		int pos_y_new = num2pos(num_y_new);

		num_x = num_x_new;
		num_y = num_y_new;
		pos_x = pos_x_new;
		pos_y = pos_y_new;
	}

	// 移動
	int up()
	{
		int num_x_new = num_x;
		int num_y_new = num_y - 1;
		int check = check_move(num_x_new, num_y_new);
		if(check == 1) {
			return 1;
		}

		num_y = num_y_new;
		pos_y = num2pos(num_y);
		return check;
	}
	int down()
	{
		int num_x_new = num_x;
		int num_y_new = num_y + 1;
		int check = check_move(num_x_new, num_y_new);
		if(check == 1) {
			return 1;
		}

		num_y = num_y_new;
		pos_y = num2pos(num_y);
		return check;
	}
	int left()
	{
		int num_x_new = num_x - 1;
		int num_y_new = num_y;
		int check = check_move(num_x_new, num_y_new);
		if(check == 1) {
			return 1;
		}

		num_x = num_x_new;
		pos_x = num2pos(num_x);
		return check;
	}
	int right()
	{
		int num_x_new = num_x + 1;
		int num_y_new = num_y;
		int check = check_move(num_x_new, num_y_new);
		if(check == 1) {
			return 1;
		}

		num_x = num_x_new;
		pos_x = num2pos(num_x);
		return check;
	}

private:

	// 位置座標(pos_x=80)から位置No(num_x=1)へ変換
	int pos2num(int pos)
	{
		return (int)((pos + 40) / size);
	}
	// 位置No(num_x=1)から位置座標(pos_x=80)へ変換
	int num2pos(int num)
	{
		return (int)(num * size);
	}

};

#endif /* APPLICATION_USER_GUI_POS_H_ */
