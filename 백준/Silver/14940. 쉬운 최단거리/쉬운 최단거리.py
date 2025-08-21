from collections import deque
dx=[-1,1,0,0]
dy=[0,0,-1,1]
def bfs(n,m,grid,dist,q):
    while(q):
        y,x=q.popleft()
        for i in range(4):
            nx,ny=x+dx[i],y+dy[i]
            if 0 <= nx < m and 0 <= ny < n:
                if grid[ny][nx]==1 and dist[ny][nx] == -1:
                    dist[ny][nx] = dist[y][x] + 1
                    q.append((ny,nx))

def main():
    n,m=map(int,input().split())
    grid=[]
    dist=[[-1]*m for _ in range(n)]
    q=deque()
    for i in range(n):
        r=list(map(int,input().split()))
        grid.append(r)
        for j in range(m):
            if r[j]==2:
                q.append((i,j))
                dist[i][j]=0
            elif r[j]==0:
                dist[i][j]=0
    bfs(n,m,grid,dist,q)

    for i in range(n):
        print(' '.join(map(str,dist[i])))

if __name__ == "__main__":
    main()