line = input().split()
# line = [H, W]

# 縦(H)と横(W)を取得
H = int(line[0])
W = int(line[1])

str = []

# 1行毎のピクセル配列を追加
# [a, b, c]のようなリストとして追加
for i in range(H):
    str.append(list(input()))

# str =
# [
#    [a, b, c],
#    [a, r, c]
# ]

# for文で回して
# 要素の頭と尻に"#"を追加 (insert, append)

for i in str:
    # i = [a, b, c]
    i.insert(0, "#")
    i.append("#")
    # i = [#, a, b, c, #]

# #行
sharpRow = ["#" for i in range(W+2)]

str.insert(0, sharpRow)
str.append(sharpRow)

# #####
# #abc#
# #arc#
# #####

for i in str:
    print("".join(i))
