/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putboxes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsato <giraffumin@gmail.com>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 07:12:08 by fsato             #+#    #+#             */
/*   Updated: 2020/09/19 20:35:59 by fsato            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

/* 日本語のコメントは提出時までに削除*/

/* boxesの多重配列と問題文の表の関係は以下の通りです
** box[0][0] | box[0][1] | box[0][2] | box[0][3]
** ----------+-----------+-----------+----------
** box[1][0] | box[1][1] | box[1][2] | box[1][3]
** ----------+-----------+-----------+----------
** box[2][0] | box[2][1] | box[2][2] | box[2][3]
** ----------+-----------+-----------+----------
** box[3][0] | box[3][1] | box[3][2] | box[3][3]
** 値が０の場合、箱がまだ置かれていないことを表します。
*/

/* かほりんさん、norminetteをお願いします。今putboxes.cに全ての関数が入っていて、長すぎると怒られるはずなので、複数ファイルに分ける必要があると思います。また、関数の中も長すぎるので、別の関数に分担させる必要があると思います。 */

/*
** fill_numbers
** ４つ分のint配列を新たに作成し、
** int a,b,c,dを配列に入れる関数です。
** 各boxに入れるint配列を返す役割。配列の先頭アドレスを返す
*/
int	*fill_numbers(int a, int b, int c, int d)
{
	int *line;

	line = malloc(sizeof(int) * 4);
	line[0] = a;
	line[1] = b;
	line[2] = c;
	line[3] = d;
	return line;
}

/*
** store_possible_pattern
** 箱の両脇(rowleftとrowright)の数字に応じて、その行に入る４箱（サイズ４のint配列）の全パターン（int配列の配列）をint**で返す関数です。0は終端を表すため？
*/

int		**store_possible_pattern(int front, int back)
{
	int i;
	int **res;

	i = 0;
	if (front == 1 && back == 2)
	{
		res = malloc(sizeof(int*) * 3);
		res[0] = fill_numbers(4, 2, 1, 3);
		res[1] = fill_numbers(4, 1, 2, 3);
		res[2] = 0;
	}
	if (front == 1 && back == 3)
	{
		res = malloc(sizeof(int*) * 4);
		res[0] = fill_numbers(4, 1, 3, 2);
		res[1] = fill_numbers(4, 2, 3, 1);
		res[2] = fill_numbers(4, 3, 1, 2);
		res[3] = 0;
	}
	if (front == 1 && back == 4)
	{
		res = malloc(sizeof(int*) * 2);
		res[0] = fill_numbers(4, 3, 2, 1);
		res[1] = 0;
	}
	if (front == 2 && back == 2)
	{
		res = malloc(sizeof(int*) * 7);
		res[0] = fill_numbers(1, 4, 2, 3);
		res[1] = fill_numbers(2, 1, 4, 3);
		res[2] = fill_numbers(2, 4, 1, 3);
		res[3] = fill_numbers(3, 1, 4, 2);
		res[4] = fill_numbers(3, 2, 4, 1);
		res[5] = fill_numbers(3, 4, 1, 2);
		res[6] = 0;
	}
	if (front == 2 && back == 3)
	{
		res = malloc(sizeof(int*) * 4);
		res[0] = fill_numbers(1, 4, 3, 2);
		res[1] = fill_numbers(2, 4, 3, 1);
		res[2] = fill_numbers(3, 4, 2, 1);
		res[3] = 0;
	}
	if (front == 2 && back == 1)
	{
		res = malloc(sizeof(int*) * 3);
		res[0] = fill_numbers(3, 1, 2, 4);
		res[1] = fill_numbers(3, 2, 1, 4);
		res[2] = 0;
	}
	if (front == 3 && back == 1)
	{
		res = malloc(sizeof(int*) * 4);
		res[0] = fill_numbers(2, 3, 1, 4);
		res[1] = fill_numbers(1, 3, 2, 4);
		res[2] = fill_numbers(2, 1, 3, 4);
		res[3] = 0;
	}
	if (front == 4 && back == 1)
	{
		res = malloc(sizeof(int*) * 2);
		res[0] = fill_numbers(1, 2, 3, 4);
		res[1] = 0;
}
	if (front == 3 && back == 2)
	{
		res = malloc(sizeof(int*) * 4);
		res[0] = fill_numbers(2, 3, 4, 1);
		res[1] = fill_numbers(1, 3, 4, 2);
		res[2] = fill_numbers(1, 2, 4, 3);
		res[3] = 0;
	}
	return (res);
}

/*
** if boxes are rightly put, return 1.
** else return 0.
*/


/*
** make_line
** 箱の多重配列boxesから、方向(direction)と列/行番号を指定して、配列(buf)に格納する関数です。
** 例えば、make_line(boxes, buf, 'u', 3)の場合、col3upからcol3downまでの４つの数字を配列bufに格納します。引数の二重配列を一重配列に切り出すもの
** direction = {u(up), d(down), r(right), l(left)}
*/
int *make_line(int **boxes, int *buf, char direction, int n)
{
	int i;

	i = 0;
	if (direction == 'l')
	{
		while(i < 4)
		{
			buf[i] = boxes[n][i];
			i++;
		}
	}
	if (direction == 'u')
	{
		while(i < 4)
		{
			buf[i] = boxes[i][n];
			i++;
		}
	}
	if (direction == 'r')
	{
		while(i < 4)
		{
			buf[i] = boxes[n][3 - i];
			i++;
		}
	}
	if (direction == 'd')
	{
		while(i < 4)
		{
			buf[i] = boxes[3 - i][n];
			i++;
		}
	}
	return buf;
}

/*
** count_visible_box
** ある一列（一行）にある箱たち(line)を手前から奥に見て、いくつ箱が見えるかをintで返す関数です。
*/

int count_visible_box(int *line)
{
	int i;
	int j;
	int res;

	i = 0;
	j = 0;
	res = 1;
	while (j < 4)
	{
		if(line[i] == 0)
		{
			res = 0;
			break ;
		}
		if (line[i] < line[j])
		{
			res++;
			i = j;

		}
		j++;
	}
	return (res);
}

/*
** have_same_num
** ある一行（一列）の箱たちの高さが、重複しているか調べる関数です。重複していたら1、いなかったら0を返します。
*/

int have_same_num(int *line)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = i + 1;
		while (j < 4)
		{
			if (line[i] == line[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/*
** verify
** 箱たちの集まりboxesが、問題文の条件を満たしているか調べる関数です。問題文のcol*up, row*left, col*down, row*rightがそのまま引数に対応しています。箱がない場所があったり、条件に合わないと0、条件に合うと1を返します。count_visible_boxの値が指定された見える箱の数と一致しているか、同じ行(列)に同じ値がないかなどが条件(leftとup方向で確認している)。
*/

int verify(int **boxes, int *colup, int *coldown, int *rowleft, int *rowright)
{
	int i;
	int j;
	int count;
	int *buf;

	i = 0;
	j = 0;
	buf = malloc(sizeof(int) * 4);
	while (i < 4)
	{
		buf = make_line(boxes, buf, 'l', i);
		if (have_same_num(buf))
		{
			return (0);
		}
		count = count_visible_box(buf);
		if (count != rowleft[i])
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		buf = make_line(boxes, buf, 'u', i);
		if (have_same_num(buf))
		{
			return (0);
		}
		count = count_visible_box(buf);
		if (count != colup[i])
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		count = count_visible_box(make_line(boxes, buf, 'r', i));
		if (count != rowright[i])
		{
			return (0);
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		count = count_visible_box(make_line(boxes, buf, 'd', i));
		if (count != coldown[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

/*
** print_boxes
** 箱たちをwrite関数で出力する関数です。最終的なouput担当
** デバッグなどにもご利用ください。
*/

void	print_boxes(int **boxes)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = '0' + boxes[i][j];
			write(1, &c, 1);
			if (j < 3)
			{
				write(1, " ", 1);
			}
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

/*
** recc_putboxes() is Recursive function.
** if it can find the right pattern, return 1.
** otherwise, return 0.
**
** 再帰的に、箱の配置全パターンを洗い出す関数です。箱の配置が条件を満たしているかをまずverifyで調べて、正しかったら箱の並び方をprint_boxesで出力してから1を返します。正しくない場合、他の箱の配置をboxesに配列として入れて、recc_putboxesを再帰的に呼び出します。いずれの再帰呼び出しでも0が帰ってきた（＝どのパターンでもうまい箱の置き方が見つからなかった）場合、０を返します。
*/

int	recc_putboxes(int **boxes, int *args)
{
	int	i;
	int	j;
	int k;
	int	**possible_patterns;
	int	colup[4];
	int	coldown[4];
	int	rowleft[4];
	int	rowright[4];

	possible_patterns = NULL;
	i = j = 0;
	while (i < 4)
	{
		colup[i] = args[i];
		coldown[i] = args[i + 4];
		rowleft[i] = args[i + 8];
		rowright[i] = args[i + 12];
		i++;
	}
	i = 0;
	if (verify(boxes, colup, coldown, rowleft, rowright) == 1)
	{
		print_boxes(boxes);
		return (1);
	}
	else
	{
		while (i < 4 && boxes[i][0] != 0)
		{
			i++;
		}
		if (i == 4)
		{
			return (0);
		}
		possible_patterns = store_possible_pattern(rowleft[i], rowright[i]);
		j = 0;
		while (possible_patterns[j] != 0)
		{
			k = 0;
			while (k < 4)
			{
				boxes[i][k] = possible_patterns[j][k];
				k++;
			}
			k = i + 1;
			while (k < 4)
			{
				boxes[k] = fill_numbers(0, 0, 0, 0);
				k++;
			}
			if (recc_putboxes(boxes, args))
			{
				return (1);
			}
			j++;
		}
	}
	return (0);
}

/*
** put_boxes
** 最初に呼び出す関数です。
** boxesの初期化を行い、recc_putboxesを呼び出します。
** パターンがみつからなかったらerrorを出力します。
*/

void	put_boxes(int **boxes, int *args)
{
	int i;
	int j;

	i = 0;
	boxes = malloc(sizeof(int*) * 5);
	while (i < 4)
	{
		boxes[i] = malloc(sizeof(int) * 4);
		j = 0;
		while (j < 4)
		{
			boxes[i][j] = 0;
			j++;
		}
		i++;
	}
	boxes[4] = NULL;
	if (!recc_putboxes(boxes, args))
	{
		write(1, "Error", 5);
	}
}
