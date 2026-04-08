# [Diamond III] Domes - 23194 

[문제 링크](https://www.acmicpc.net/problem/23194) 

### 성능 요약

메모리: 4044 KB, 시간: 4 ms

### 분류

기하학, 다각형의 넓이, 반평면 교집합

### 제출 일자

2026년 4월 8일 23:23:08

### 문제 설명

<p>Saint Basil’s Cathedral is the best-known landmark of Moscow and maybe even of all of Russia. Built under Ivan the Terrible in the 16<sup>th</sup> century, the cathedral is known for its colorful domes. No visit to the city is complete without taking a photo of the former church in Red Square.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/62b96fa1-a172-4555-9fbc-f52050dc3a8b/-/preview/" style="width: 421px; height: 237px;"></p>

<p style="text-align: center;">Figure C.1: Two views of Saint Basil’s Cathedral.</p>

<p>The Moscow Tourism Board (MTB) wants to make it as safe as possible for tourists to take the perfect shot of the cathedral. Depending on where you stand when you take a picture, the relative positions of the domes will be different (see Figure C.1). The MTB is concerned that for some desired configurations of domes the region in Red Square where such a photo is possible will be so small as to lead to a dangerous overcrowding of photographers. Wanting to avoid the inevitable pushing, shoving, injury, and Covid that this could cause, the MTB would like to find the area of the region where a photo is possible for any desired ordering of the domes.</p>

<p style="text-align: center;"><img alt="" src="https://upload.acmicpc.net/716a24d9-54d6-4268-8a27-043216ac6177/-/preview/" style="width: 125px; height: 126px;"></p>

<p style="text-align: center;">Figure C.2: Illustration of the sample inputs.</p>

<p>For simplicity, assume that cameras have a 180-degree viewing angle. As an illustration consider Figure C.2, which shows the location of the domes (labeled 1–5) and the photographer (green dot) in the plane. If the photographer shoots a picture aiming the camera straight towards the left (directly at dome 5), then everything in the shaded area will be visible in the photograph. Note that in this photograph, the domes will appear in order 4, 3, 5, 2, 1 from the left to the right.</p>

<p>Given the location of the domes within Red Square and a desired left-toright order of the domes in the photograph, MTB wants to know the area of the region within Red Square from which such a photograph can be taken. You can assume that the domes are points, so that they do not block each other unless they are in a straight line from the photographer’s view.</p>

### 입력 

 <p>The first line of input contains three integers d<sub>x</sub>, d<sub>y</sub>, and n, where d<sub>x</sub> and d<sub>y</sub> (2 ≤ d<sub>x</sub>, d<sub>y</sub> ≤ 10<sup>5</sup>) are the dimensions of Red Square, and n (1 ≤ n ≤ 100) is the number of domes. The bottom-left corner of Red Square is at the origin (0, 0) and the top-right corner is at coordinate (d<sub>x</sub>, d<sub>y</sub>).</p>

<p>Each of the next n lines contains two integers x<sub>i</sub> and y<sub>i</sub> (0 < x<sub>i</sub> < d<sub>x</sub>, 0 < y<sub>i</sub> < d<sub>y</sub>), giving the locations (x<sub>i</sub>, y<sub>i</sub>) of the domes. The i<sup>th</sup> line describes dome number i. No two domes are in the same location.</p>

<p>The last line contains a permutation of the numbers {1, . . . , n} specifying the desired left-to-right viewing order of the domes in the picture.</p>

### 출력 

 <p>Output the area of the region within Red Square from which one can take a photo that shows the domes in the requested order. Note that the area may be 0 if there is no position from which to take the requested photo. Your answer should have an absolute or relative error of at most 10<sup>−3</sup>.</p>

