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



		      disorder
                 │
        ┌────────┼────────┐
        │        │        │
      < 0.2    < 0.5    >= 0.5
        │        │        │
        ▼        ▼        ▼
     SIMPLE    MEDIUM   COMPLEX    //adaptive de duruma göre		  hangisinin kullanılacağına karar verir 
