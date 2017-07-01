#include "../includes/vm.h"

// reference au moins une fonction test pour chaque instruction.
// ces fonctions test supplantent la fonction run().

int						live_test(t_argv info)
{
	t_plst				*head;

	head = init_process(info);
	head->proc.instruct = malloc(sizeof(head->proc.instruct));
	head->proc.instruct->size = 2;
	head->proc.instruct->opcode = 1;

	int					args[4] = {1};
	int					types[4] = {0};
	head->proc.instruct->args = args;
	head->proc.instruct->types = types;

	ft_printf("avant live : %d\n", head->proc.pc);
	_live(&head->proc, head->proc.instruct);
	ft_printf("apres live : %d\n", head->proc.pc);
	return (0);
}

int                                             ld_test(t_argv info) // test
{
        t_plst                          *head;

        head = init_process(info);
        head->proc.instruct = malloc(sizeof(head->proc.instruct));
        head->proc.instruct->size = 8;
        head->proc.instruct->opcode = 2;

        int                                     args[4] = {5, 1};
        int                                     types[4] = {T_REG};
        head->proc.instruct->args = args;
        head->proc.instruct->types = types;

        ft_printf("avant ld :\npc: %d\nreg: %d\n---\n", head->proc.pc);
        _ld(&head->proc, head->proc.instruct, info.arena);
        ft_printf("apres ld :\npc: %d\nreg: %d\n---\n", head->proc.pc);
        return (0);
}
