opengl software

dados = csvread('oak_search.csv');
grid on;
hold on;
plot(dados(:, 2), dados(:, 3));
plot(dados(:, 2), dados(:, 4));
title('OakByNorm - Busca');
xlabel('Quantidade de Elementos Inseridos');
ylabel('Tempo de Busca (ms)');
legend('tempo busca STL', 'tempo busca aluno');

figure
grid on;
hold on;
plot(log(dados(:, 2)), dados(:, 3), 'b*');
title('Fit Logar�tmico para busca STL');
xlabel('log(# elementos inseridos)');
ylabel('Tempo (ms)');
legend('busca STL');

figure
grid on;
hold on;
plot(log(dados(:, 2)), dados(:, 4), 'r*');
title('Fit Logar�tmico para busca aluno');
xlabel('log(# elementos inseridos)');
ylabel('Tempo (ms)');
legend('busca aluno');

figure
grid on;
hold on;
plot(log(dados(:, 2)), dados(:, 3));
plot(log(dados(:, 2)), dados(:, 4));
title('OakByNorm - Busca');
xlabel('log(# elementos inseridos)');
ylabel('Tempo (ms)');
legend('busca STL', 'busca aluno');

figure;
grid on;
hold on;
plot(dados(:, 2), dados(:, 5));
plot(dados(:, 2), dados(:, 6));
title('OakByNorm - Inser��es');
xlabel('Quantidade de Elementos Inseridos');
ylabel('Tempo de Inser��o (ms)');
legend('tempo inser��es STL', 'tempo inser��es aluno');

figure
grid on;
hold on;
plot(log(dados(:, 2)), dados(:, 5), 'b*');
title('Fit Logar�tmico para inser��o STL');
xlabel('log(# elementos inseridos)');
ylabel('Tempo (ms)');
legend('inser��o STL');

figure
grid on;
hold on;
plot(log(dados(:, 2)), dados(:, 6), 'r*');
title('Fit Logar�tmico para inser��o aluno');
xlabel('log(# elementos inseridos)');
ylabel('Tempo (ms)');
legend('inser��o aluno');

figure
grid on;
hold on;
plot(log(dados(:, 2)), dados(:, 5));
plot(log(dados(:, 2)), dados(:, 6));
title('OakByNorm - Inser��o');
xlabel('log(# elementos inseridos)');
ylabel('Tempo (ms)');
legend('inser��o STL', 'inser��o aluno');

% fid = fopen('torusALU.asc', 'r');
% data = fscanf(fid, '%g', [3, Inf]).';
% fclose(fid);
% scatter3(data(:,1), data(:,2), data(:,3));