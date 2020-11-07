# 【関数一覧】

## ①int *fill_numbers(int a, int b, int c, int d)

* 戻り値＞return line;
* 関数の役割＞引き取った４つの整数を１つの配列であつかう。0で穴埋めする。
* 出てくる関数＞malloc
* ノミネトエラ＞



## ② int     **store_possible_pattern(int front, int back)

* 戻り値＞return (res);
* 関数の役割＞組み合わせ算出
* 出てくる関数＞malloc、fill_numbers
* ノミネトエラ＞「function store_possible_pattern has 74 lines」⇒行数減らす（関数わける？）



## ③int *make_line(int **boxes, int *buf, char direction, int n)

* 戻り値＞return buf;
* 関数の役割＞各方面から見た時の各行列に値を入れていく
* 出てくる関数＞なし
* ノミネトエラ＞「function make_line has 36 lines」⇒行数減らす（関数わける？）



## ④int count_visible_box(int *line)

* 戻り値＞return (res);
* 関数の役割＞何個箱がみえるのかを確認
* 出てくる関数＞
* ノミネトエラ＞



## ⑤int have_same_num(int *line)

* 戻り値＞return (0); or return (1);
* 関数の役割＞各行、各列で重複する値がないか確認
* 出てくる関数＞
* ノミネトエラ＞



## ⑥ int verify(int **boxes, int *colup, int *coldown, int *rowleft, int *rowright)

* 戻り値＞return (0); or return (1);
* 関数の役割＞箱の中身の組み合わせが正しいかチェックする
* 出てくる関数＞malloc、make_line、have_same_num、 count_visible_box
* ノミネトエラ＞「function verify has 58 lines」⇒行数減らす（関数わける？）、「verify have 5 parameters」⇒変数どうしよっか



## ⑦void    print_boxes(int **boxes)

* 戻り値＞なし
* 関数の役割＞
* 出てくる関数＞write
* ノミネトエラ＞



## ⑧int recc_putboxes(int **boxes, int *args)

* 戻り値＞return (0); or return (1);
* 関数の役割＞
* 出てくる関数＞verify、print_boxes、store_possible_pattern、fill_numbers、recc_putboxes
* ノミネトエラ＞」function recc_putboxes has 59 lines」⇒行数減らす（関数わける？）、「recc_putboxes has 8 variables、2 assignations」⇒とにかくi=j=0;はNG
* 



## ⑨ void    put_boxes(int **boxes, int *args)

* 戻り値＞なし
* 関数の役割＞boxの初期化
* 出てくる関数＞malloc,recc_putboxes
* ノミネトエラ＞



# 【めも】

malloc：メモリを動的にあつかう（大は小をかねる）

