/* Написать программу вычисления стоимости покупки с учётом скидки.
 * Скидка в X процентов предоставляется,
 * если сумма покупки больше A рублей,
 * в Y процентов - если сумма больше B рублей.
 * В стандартном вводе содержится пять вещественных чисел,
 * разделённых пробелом: N, A, B, X, Y (A < B) - где N
 * - исходная стоимость товара.
 * Выведите стоимость покупки с учётом скидки.
 */

#ifndef STUDY_C_DISCOUNT_H
#define STUDY_C_DISCOUNT_H

double discount(double N, double A, double B, double X, double Y) {
    double prise = 0;
    if (N > B) {
        prise = N * (1 - (Y/100));
    } else if (N > A) {
        prise = N * (1 - (X/100));
    } else {
        prise = N;
    }
    return prise;
}

#endif //STUDY_C_DISCOUNT_H
