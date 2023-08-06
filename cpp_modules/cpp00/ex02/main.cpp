/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysrondy <ysrondy@student.codam.nl>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 16:37:01 by ysrondy           #+#    #+#             */
/*   Updated: 2023/08/06 16:37:01 by ysrondy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hh"
#include <iostream>

int main(void)
{
	Account account1(42);
	Account account2(54);
	Account account3(957);
	Account account4(432);
	Account account5(1234);
	Account account6(0);
	Account account7(754);
	Account account8(16576);

	Account::displayAccountsInfos();

	account1.displayStatus();
	account2.displayStatus();
	account3.displayStatus();
	account4.displayStatus();
	account5.displayStatus();
	account6.displayStatus();
	account7.displayStatus();
	account8.displayStatus();

	account1.makeDeposit(5);
	account2.makeDeposit(765);
	account3.makeDeposit(564);
	account4.makeDeposit(2);
	account5.makeDeposit(87);
	account6.makeDeposit(23);
	account7.makeDeposit(9);
	account8.makeDeposit(20);

	Account::displayAccountsInfos();

	account1.displayStatus();
	account2.displayStatus();
	account3.displayStatus();
	account4.displayStatus();
	account5.displayStatus();
	account6.displayStatus();
	account7.displayStatus();
	account8.displayStatus();

	account1.makeWithdrawal(50);
	account2.makeWithdrawal(34);
	account3.makeWithdrawal(657);
	account4.makeWithdrawal(4);
	account5.makeWithdrawal(76);
	account6.makeWithdrawal(50);
	account7.makeWithdrawal(657);
	account8.makeWithdrawal(7654);

	Account::displayAccountsInfos();

	account1.displayStatus();
	account2.displayStatus();
	account3.displayStatus();
	account4.displayStatus();
	account5.displayStatus();
	account6.displayStatus();
	account7.displayStatus();
	account8.displayStatus();

	return (0);
}
