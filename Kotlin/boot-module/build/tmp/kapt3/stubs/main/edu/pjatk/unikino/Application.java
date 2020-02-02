package edu.pjatk.unikino;

import java.lang.System;

@kotlin.Metadata(mv = {1, 1, 10}, bv = {1, 0, 2}, k = 1, d1 = {"\u00006\n\u0002\u0018\u0002\n\u0002\u0010\u0000\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\n\u0002\u0018\u0002\n\u0000\b\u0017\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J8\u0010\u0003\u001a\u00020\u00042\u0006\u0010\u0005\u001a\u00020\u00062\u0006\u0010\u0007\u001a\u00020\b2\u0006\u0010\t\u001a\u00020\n2\u0006\u0010\u000b\u001a\u00020\f2\u0006\u0010\r\u001a\u00020\u000e2\u0006\u0010\u000f\u001a\u00020\u0010H\u0017\u00a8\u0006\u0011"}, d2 = {"Ledu/pjatk/unikino/Application;", "", "()V", "init", "Lorg/springframework/boot/CommandLineRunner;", "filmRepository", "Ledu/pjatk/unikino/boot/FilmRepository;", "klientRepository", "Ledu/pjatk/unikino/boot/KlientRepository;", "rezerwacjaRepository", "Ledu/pjatk/unikino/boot/RezerwacjaRepository;", "seansRepository", "Ledu/pjatk/unikino/boot/SeansRepository;", "salaRepository", "Ledu/pjatk/unikino/boot/SalaRepository;", "kinoteatrRepository", "Ledu/pjatk/unikino/boot/KinoteatrRepository;", "boot-module"})
@org.springframework.boot.autoconfigure.SpringBootApplication()
public class Application {
    
    @org.jetbrains.annotations.NotNull()
    @org.springframework.context.annotation.Bean()
    public org.springframework.boot.CommandLineRunner init(@org.jetbrains.annotations.NotNull()
    edu.pjatk.unikino.boot.FilmRepository filmRepository, @org.jetbrains.annotations.NotNull()
    edu.pjatk.unikino.boot.KlientRepository klientRepository, @org.jetbrains.annotations.NotNull()
    edu.pjatk.unikino.boot.RezerwacjaRepository rezerwacjaRepository, @org.jetbrains.annotations.NotNull()
    edu.pjatk.unikino.boot.SeansRepository seansRepository, @org.jetbrains.annotations.NotNull()
    edu.pjatk.unikino.boot.SalaRepository salaRepository, @org.jetbrains.annotations.NotNull()
    edu.pjatk.unikino.boot.KinoteatrRepository kinoteatrRepository) {
        return null;
    }
    
    public Application() {
        super();
    }
}