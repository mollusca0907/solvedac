N = int(input())
vote_list = list(map(int, input().split()))

vote_count = [0] * N
skip_count = 0

for vote in vote_list:
    if vote == 0:
        skip_count += 1
    else:
        vote_count[vote - 1] += 1

max_vote = max(vote_count)
max_vote_count = vote_count.count(max_vote)

if max_vote_count == 1:
    print(vote_count.index(max_vote) + 1)
elif max_vote <= skip_count:
    print('skipped')
else:
    print('skipped')