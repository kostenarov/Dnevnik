# Dnevnik
ПРОЕКТ ЗА ЛЯТНА ПРАКТИКА 10 КЛАС
Тайно дневниче

Целта на този проект е да реализирате конзолен таен дневник.

Базов дневник:
Потребителят трябва при пускане на приложението да може да избира между това да въведе нова история или да разглежда списък от стари истории които да може да отвори и да прочете.

При въвеждане на нова история потребителят въвежда на коя дата се е случила историята, заглавието й и самата история. Заглавието може да е не повече от 30 символа.

При разглеждане трябва да се изобразява списък с всички истории (техните заглавия и дати). 
Незадължително, но бонус ако се направи - сортиране на историите по дата на въвеждане (най-отгоре най-новите), извеждането им страница по страница (страницата може да е с константен размер 10 истории на страница или пък потребителя да избира колко истории на страница да се извеждат).
При разглеждане на историята да се изписва целия текст.

Историите да се пазят на файловата система.

Допълнение №1
Файлът да се криптира с парола зададена от потребителя. При пускане на приложението да се изисква парола, при грешно въведена парола да няма достъп до дневника.

Допълнение №2
Дневникът да има възможност да се използва от няколко човека.

Допълнение №3
Да се имплементира бързо търсене на история по заглавие или по дата. Желаната сложност е O(n*logn) където n е броя истории.
