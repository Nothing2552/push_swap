push_swap/
│
├── Makefile
├── push_swap.h
├── README.md
├── main.c
│
├── parsing/
│   ├── parse_args.c
│   ├── check_args.c
│   └── init_stack.c
│
├── operations/
│   ├── swap.c
│   ├── push.c
│   ├── rotate.c
│   └── reverse_rotate.c
│
├── utils/
│   ├── stack_utils.c
│   ├── stack_utils2.c
│   ├── sort_utils.c
│   └── error.c
│
├── algorithms/
│   ├── simple.c
│   ├── medium.c
│   ├── complex.c
│   ├── adaptive.c
│   └── disorder.c
│
├── benchmark/
│   └── benchmark.c
│
└── libft/

---------------------------------------------------------------------
                ./push_swap 8 3 5 1
                         │
                         ▼
                 Argümanları kontrol et
                         │
              ┌──────────┴──────────┐
              │                     │
           geçerli                hatalı
              │                     │
              ▼                     ▼
         Stack A oluştur          Error
              │
              ▼
       Disorder hesapla
              │
              ▼
      Hangi algoritmayı
       kullanacağına karar ver
              │
              ▼
          A ve B üzerinde
       operasyonları uygula
              │
              ▼
       pb / ra / sa / pa ...
              │
              ▼
          A sıralandı
              │
              ▼
          memory free

-------------------------------------------------------------------

		        ADAPTIVE
                    │
                    ▼
            disorder hesapla
                    │
        ┌───────────┼───────────┐
        │           │           │
 disorder < 0.2   < 0.5      >= 0.5
        │           │           │
        ▼           ▼           ▼
     SIMPLE       MEDIUM      COMPLEX
     O(n²)        O(n√n)      O(n log n)

-------------------------------------------------------------------------

                    push_swap
                       │
              ┌────────┴────────┐
              ↓                 ↓
           stdout             stderr
              │                 │
       sa / pb / ra...       benchmark
              │              bilgileri
              └────────┬────────┘
                       ↓
                    TERMINAL
// farklı kanallar ama aynı terminalde gösterilir.

------------------------------------------------------------------

Biz stack'i C içerisinde bir şekilde temsil etmek zorundayız. Bunun için örneğin:

Array

kullanabiliriz veya:

Linked List

kullanabiliriz.

Biz linked list kullanmayı seçiyoruz.

Dolayısıyla:

                  PUSH_SWAP

               iki STACK var
                  A     B
                  │     │
                  └──┬──┘
                     │
              C'de nasıl tutalım?
                     │
                 Linked List

Yani "linked list mi stack mi kullanacağız?" sorusunun cevabı:

İkisini de. Stack bizim veri yapımızın davranışı; linked list ise o stack'i C'de gerçekleştirme yöntemimiz.

-----------------------------------------------------------------

Bütün projeyi şimdi tek resimde görelim

Terminal:

./push_swap 5 2 8 1

↓

             argc / argv

          "5" "2" "8" "1"
                 │
                 ▼
              PARSING
       Geçerli sayılar mı?
       Duplicate var mı?
       int sınırında mı?
                 │
                 ▼
              STACK A
       Linked list ile tutuyoruz

       [5] → [2] → [8] → [1]

              STACK B

                 NULL
                 │
                 ▼
              ALGORITHM

        "Hangi hareketleri
             yapmalıyım?"
                 │
                 ▼
             OPERATIONS

        sa / pb / ra / ...
                 │
                 ▼
            STACK'LER DEĞİŞİR
                 │
                 ▼

       [1] → [2] → [5] → [8]

              B = NULL
--------------------------------------------------------------------
parsing/
→ terminalden gelen veriyi kontrol edip hazırlar

t_stack
→ Stack A ve B'nin elemanlarının yapısı

linked list
→ Stack A ve B'yi bellekte tutma yöntemimiz

operations/
→ Stack'leri değiştirir
  sa, pb, ra...

algorithms/
→ hangi operation'ın ne zaman yapılacağına karar verir

utils/
→ bunlara yardımcı olur
--------------------------------------------------------------------


sa, sb, ss, pa ve pb fonksiyonları yazıldı. 

stack_utils.c ye bazı yardımcı fonksiyonlar eklendi.

--------------------------------------------------------------------

Parsing kısmında yapılanlar:

parse_int
→ String olarak gelen sayının geçerli olup olmadığını kontrol eder.
→ İşaret kontrolü yapar ve int sınırını aşan değerleri reddeder.

has_duplicate
→ Stack içinde aynı sayıdan daha önce eklenmiş mi kontrol eder.

new_node
→ Gelen sayı için yeni bir linked list node'u oluşturur.

add_node_back
→ Yeni node'u Stack A'nın sonuna ekler ve argüman sırasını korur.

init_stack
→ Argümanları kontrol eder ve geçerli sayılardan Stack A'yı oluşturur.

free_stack / error_exit
→ Hata durumunda ayrılan belleği temizler ve stderr'e Error yazar.

parse_options
→ --simple, --medium, --complex, --adaptive ve --bench flag'lerini ayırır.
→ Flag verilmezse varsayılan strateji adaptive olur.

Sıradaki adım:
→ parse_options ve init_stack fonksiyonlarını main'e bağlamak.
→ "8 3 5" şeklinde tek string olarak verilen sayıları ayırmak.
