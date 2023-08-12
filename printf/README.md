```
Assignment name  : ft_printf
Expected file    : ft_printf.c
Allowed functions: malloc, free, write, va_start, va_arg, va_ccopy, va_end
-----------------------------------------------------------------------------------

Vous devez rendre une fonction nommé `ft_printf` qui reproduira une petite partie du comportement du vrai printf avec les conditions suivantes:

- Vous devez gérer uniquement les conversions suivantes : s,d et x


Votre fonction devra être prototypée de la façon suivante :

int	ft_printf(const char *, ... );

Avant de commencer nous vous conseillons la lecture du `man 3 printf` et du `man va_arg`.
Nous vous recommandons de tester votre programme en le comparant avec le vrai printf.

Votre fonction ne doit pas avoir de fuites de mémoires.

Exemples de sortie de la fonction:

call: ft_printf("Hello %s\n", "toto");
out:Hello toto$

call: ft_printf("Magic %s is %d", "number", 42);
out:Magic number is 42%

call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
out:Hexadecimal for 42 is 2a$

Rappel: Votre fonction ne dois pas avoir de fuites mémoire. Cela sera vérifié par la moulinette.
```