// https://programmers.co.kr/learn/courses/30/lessons/59039

// 이름이 없는 동물의 ID 출력
SELECT ANIMAL_ID FROM ANIMAL_INS WHERE NAME is null;

// 이름이 있는 동물의 ID 출력
SELECT ANIMAL_ID FROM ANIMAL_INS WHERE NAME is not null;