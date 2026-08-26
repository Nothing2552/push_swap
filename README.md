*This project has been created as part of the 42 curriculum by aryaprak, yaydilek.*

# push_swap

## Description

`push_swap`, tekrar etmeyen tamsayılardan oluşan bir listeyi iki stack ve sınırlı
bir operasyon kümesi kullanarak sıralayan bir C programıdır. Program sıralanmış
sayıları değil, stack A'yı küçükten büyüğe sıralayacak operasyonları standart
çıktıya yazar.

Projenin amacı yalnızca doğru sıralama yapmak değil; farklı girdi düzenleri için
uygun algoritmayı seçmek, üretilen operasyon sayısını incelemek ve algoritmik
karmaşıklığı Push_swap operasyon modeli içinde değerlendirmektir.

Başlangıçta stack A komut satırındaki sayıları içerir, ilk sayı stack'in
tepesidir ve stack B boştur. Sıralama sonunda A küçükten büyüğe sıralı, B ise boş
olmalıdır.

## Operations

| Operasyon | Açıklama |
|---|---|
| `sa`, `sb` | İlgili stack'in ilk iki elemanını değiştirir. |
| `ss` | `sa` ve `sb` işlemlerini birlikte uygular. |
| `pa` | B'nin tepesindeki elemanı A'nın tepesine taşır. |
| `pb` | A'nın tepesindeki elemanı B'nin tepesine taşır. |
| `ra`, `rb` | İlk elemanı ilgili stack'in sonuna taşır. |
| `rr` | `ra` ve `rb` işlemlerini birlikte uygular. |
| `rra`, `rrb` | Son elemanı ilgili stack'in başına taşır. |
| `rrr` | `rra` ve `rrb` işlemlerini birlikte uygular. |

Operasyonlar `stdout` üzerine, her satırda bir operasyon olacak şekilde yazılır.
Hata ve benchmark bilgileri `stderr` üzerine gönderilir.

## Data structure and indexing

Stack A ve B tek yönlü bağlı liste ile temsil edilir. Her node gerçek değeri,
sıralama indexini ve sonraki node'un adresini tutar.

```text
Values:   40 -> -5 -> 12 -> 100
Indexes:   2 ->  0 ->  1 ->   3
```

İndeksleme sırasında değerler geçici bir diziye kopyalanır, bubble sort ile
sıralanır ve her değerin derecesi binary search ile ilgili node'a yazılır.
Stack'in bağlantı sırası değişmez ve bu hazırlık Push_swap operasyonu üretmez.

## Algorithms

Program dört seçilebilir strateji içerir.

### Simple — selection sort adaptation, O(n²)

Simple strateji A'daki minimum elemanı bulur. Minimum üst yarıdaysa `ra`, alt
yarıdaysa `rra` kullanılarak en kısa yönden tepeye getirilir ve `pb` ile B'ye
gönderilir. A'daki küçük kalan bölüm özel olarak sıralandıktan sonra elemanlar
`pa` ile A'ya geri alınır.

Her turda minimumu bulmak için kalan stack tarandığından ve bu işlem elemanlar
azalana kadar tekrarlandığından üst sınırı O(n²)'dir. Anlaşılır bir başlangıç ve
karşılaştırma algoritması olması nedeniyle simple strateji olarak seçilmiştir.

### Medium — square-root chunk strategy, O(n√n) target

Medium strateji indeksleri yaklaşık `√n` genişliğinde hareketli bir pencere ile
işler. Aktif aralıktaki node'lar `pb` ile B'ye gönderilir; daha küçük indexler
`rb` ile B'nin altına yaklaştırılır. Aralığın dışındaki elemanlar `ra` ile
döndürülerek sıradaki aday incelenir.

A boşaldıktan sonra B'deki en büyük index bulunur. Konumuna göre daha kısa olan
`rb` veya `rrb` yönü seçilir ve node `pa` ile A'ya alınır. Büyük indexlerin önce
geri alınması, her yeni node A'nın tepesine geldiği için A'yı küçükten büyüğe
oluşturur. Chunk yaklaşımının hedeflenen Push_swap operasyon karmaşıklığı
O(n√n)'dir.

### Complex — binary LSD radix sort, O(n log n)

Complex strateji `0..n-1` aralığındaki indexlerin bitlerini en düşük anlamlı
bitten başlayarak işler:

- Mevcut bit `0` ise node `pb` ile B'ye gönderilir.
- Mevcut bit `1` ise node `ra` ile A'nın sonunda tutulur.
- Bit turu tamamlanınca B'deki bütün node'lar `pa` ile A'ya alınır.

Her bit turu O(n) operasyon, gerekli bit sayısı O(log n) olduğundan toplam
Push_swap operasyon üst sınırı O(n log n)'dir. Radix sort yüksek düzensizlikte
öngörülebilir performansı nedeniyle complex strateji olarak seçilmiştir.

### Adaptive strategy

Disorder, stack'teki ters sıralı çiftlerin bütün çiftlere oranıdır:

```text
disorder = inversion_count / total_pair_count
```

Değer `0` ile `1` arasındadır. Sıralı stack için `0`, tamamen ters sıralı stack
için `1` olur ve herhangi bir hareket yapılmadan önce hesaplanır.

Adaptive politika:

| Disorder | Seçilecek yöntem | Hedef karmaşıklık |
|---:|---|---:|
| `< 0.2` | Simple | O(n²) |
| `0.2 <= disorder < 0.5` | Medium | O(n√n) |
| `>= 0.5` | Complex | O(n log n) |

Düşük disorder değerinde basit yöntem mevcut düzenden yararlanabilir. Orta
seviyede chunk yaklaşımı quadratic minimum çıkarmaya göre daha düşük operasyon
hedefler. Yüksek disorder seviyesinde radix sort başlangıç düzeninden bağımsız,
öngörülebilir bir üst sınır sağlar.

## Parsing and errors

Program aşağıdaki durumları reddeder:

- Tamsayı olmayan argümanlar
- `INT_MIN..INT_MAX` aralığının dışındaki değerler
- Tekrarlanan sayılar
- Bilinmeyen veya tekrarlanan seçenekler
- Aynı anda birden fazla strateji seçilmesi
- Seçeneklerden sonra sayı bulunmaması

Hata durumunda `Error\n` stderr üzerine yazılır ve ayrılmış stack belleği serbest
bırakılır. Sayılar ayrı argümanlar veya tek quoted string olarak verilebilir.

## Instructions

### Compilation

```bash
make
```

Derleme `cc -Wall -Wextra -Werror` kullanır ve `push_swap` executable dosyasını
oluşturur.

```bash
make clean    # Object dosyalarını siler
make fclean   # Object dosyalarını ve executable'ı siler
make re       # Projeyi baştan derler
```

### Usage

Varsayılan strateji adaptive'dir:

```bash
./push_swap 4 67 3 87 23
./push_swap "4 67 3 87 23"
```

Belirli bir stratejiyi zorlamak için:

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

Benchmark modu:

```bash
./push_swap --bench --complex 4 67 3 87 23
```

Benchmark raporu başlangıç disorder yüzdesini, strateji ve karmaşıklığı, toplam
operasyon sayısını ve her operasyonun ayrı sayısını stderr üzerinde gösterir.

Yalnız toplam operasyon sayısını görmek için:

```bash
./push_swap --complex 4 67 3 87 23 | wc -l
```

### Checker ile doğrulama

```bash
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG
```

Beklenen sonuç `OK` olmalıdır. Checker başka bir klasördeyse tam yolu kullan:

```bash
ARG="4 67 3 87 23"
./push_swap --complex $ARG \
	| /home/aryaprak/Downloads/checker_linux $ARG
```

Benchmark raporunu ayrı dosyaya kaydedip operasyonları checker'a vermek için:

```bash
ARG="4 67 3 87 23"
./push_swap --bench --complex $ARG 2>benchmark.txt \
	| ./checker_linux $ARG
```

### Performance testing

```bash
ARG="$(shuf -i 0-9999 -n 100)"
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l

ARG="$(shuf -i 0-9999 -n 500)"
./push_swap $ARG | ./checker_linux $ARG
./push_swap $ARG | wc -l
```

| Boyut | Minimum geçiş | İyi | Mükemmel |
|---:|---:|---:|---:|
| 100 | `< 2000` | `< 1500` | `< 700` |
| 500 | `< 12000` | `< 8000` | `< 5500` |

Operasyon sayısının yanında checker sonucunun da `OK` olması gerekir.

## Project structure

```text
.
├── algorithms/     # Simple, medium, complex ve disorder hesaplama
├── benchmark/      # Operasyon sayaçları ve stderr raporu
├── libft/          # Kullanılan yardımcı libft fonksiyonları
├── operations/     # Bütün Push_swap operasyonları
├── parsing/        # Seçenek, integer, overflow ve duplicate kontrolleri
├── utils/          # Stack, sıralama ve hata yardımcıları
├── main.c          # Parsing, strateji seçimi ve program yaşam döngüsü
├── push_swap.h     # Veri türleri ve fonksiyon prototipleri
└── Makefile
```

## Team contributions

Proje iki öğrenci tarafından ortak geliştirilmiştir. Parsing, stack oluşturma,
hata yönetimi, operasyonlar, algoritmalar, benchmark sistemi, testler ve
dokümantasyon birlikte gözden geçirilmiştir. Her iki ekip üyesinin de bütün
stratejileri ve program akışını açıklayabilmesi hedeflenmiştir.

## Resources

- Projeyle birlikte sağlanan `en.subject.pdf`
- [C language reference](https://en.cppreference.com/w/c)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)
- [Linked list](https://en.wikipedia.org/wiki/Linked_list)
- [Big O notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- [Binary search](https://en.wikipedia.org/wiki/Binary_search_algorithm)

### Use of AI

AI; subject maddelerini açıklamak, komut satırı parsing ve stack operasyonlarını
gözden geçirmek, edge-case testleri önermek, selection/chunk/radix
algoritmalarının çalışma mantığını tartışmak, benchmark ile stdout/stderr
ayrımını açıklamak ve README yapısını hazırlamak için yardımcı araç olarak
kullanılmıştır.

AI çıktıları doğrudan doğruluk kanıtı olarak kabul edilmemiştir. Öneriler ekip
tarafından okunmuş, kodla karşılaştırılmış ve derleyici, Norminette, rastgele
testler ve sağlanan checker ile doğrulanmak üzere değerlendirilmiştir. Teslim
edilen kodu anlama ve savunma sorumluluğu ekip üyelerine aittir.
