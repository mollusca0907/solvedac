# [Platinum I] Bojanje stabla - 28587 

[문제 링크](https://www.acmicpc.net/problem/28587) 

### 성능 요약

메모리: 21904 KB, 시간: 120 ms

### 분류

자료 구조, Heavy-light 분할, 느리게 갱신되는 세그먼트 트리, 세그먼트 트리, 트리

### 제출 일자

2025년 12월 2일 01:00:45

### 문제 설명

<p>Zadano je stablo od $N$ čvorova označenih prirodnim brojevima od $1$ do $N$. Svaki čvor ima pridruženu neku vrijednost. Na početku su vrijednosti svih čvorova jednake nuli. Mirko je odlučio nekoliko puta promijeniti vrijednosti nekih čvorova. Preciznije, u i-tom mijenjanju, postavit će vrijednosti svih čvorova na putu od $a_i$ do $b_i$ na $i$. Njegov znatiželjni prijatelj Slavko će ga povremeno upitati koja je trenutno vrijednost pridružena određenom čvoru. Pomozi Mirku odgovoriti na Slavkova pitanja.</p>

### 입력 

 <p>U prvom retku je prirodni broj $N$, broj iz teksta zadatka.</p>

<p>U sljedećih $N-1$ redaka su po $2$ prirodna broja $a$ i $b$, parovi čvorova zadanog stabla koji su spojeni bridom.</p>

<p>Nakon toga se u zasebnom retku nalazi prirodni broj $M$ koji je jednak zbroju broja Mirkovih mijenjanja i Slavkovih pitanja. Svaki od sljedećih $M$ redaka je jednog od dva oblika:</p>

<ul>
	<li>$1$ $a_i$ $b_i$ – Mirkova promjena: Ako je ovo $i$-to mijenjanje čvorova, postavi vrijednosti svih čvorova na putu od $a_i$ do $b_i$ na $i$.</li>
	<li>$2$ $x$ – Slavkovo pitanje: Koja je trenutna vrijednost čvora s oznakom $x$?</li>
</ul>

### 출력 

 <p>Redom, u zasebnim retcima odgovori na Slavkova pitanja.</p>

