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
title('Fit Logarítmico para busca STL');
xlabel('log(# elementos inseridos)');
ylabel('Tempo (ms)');
legend('busca STL');

figure
grid on;
hold on;
plot(log(dados(:, 2)), dados(:, 4), 'r*');
title('Fit Logarítmico para busca aluno');
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
title('OakByNorm - Inserções');
xlabel('Quantidade de Elementos Inseridos');
ylabel('Tempo de Inserção (ms)');
legend('tempo inserções STL', 'tempo inserções aluno');

figure
grid on;
hold on;
plot(log(dados(:, 2)), dados(:, 5), 'b*');
title('Fit Logarítmico para inserção STL');
xlabel('log(# elementos inseridos)');
ylabel('Tempo (ms)');
legend('inserção STL');

figure
grid on;
hold on;
plot(log(dados(:, 2)), dados(:, 6), 'r*');
title('Fit Logarítmico para inserção aluno');
xlabel('log(# elementos inseridos)');
ylabel('Tempo (ms)');
legend('inserção aluno');

figure
grid on;
hold on;
plot(log(dados(:, 2)), dados(:, 5));
plot(log(dados(:, 2)), dados(:, 6));
title('OakByNorm - Inserção');
xlabel('log(# elementos inseridos)');
ylabel('Tempo (ms)');
legend('inserção STL', 'inserção aluno');

% fid = fopen('torusALU.asc', 'r');
% data = fscanf(fid, '%g', [3, Inf]).';
% fclose(fid);
% scatter3(data(:,1), data(:,2), data(:,3));