package edu.pjatk.unikino.ui;

import java.lang.System;

@kotlin.Metadata(mv = {1, 1, 10}, bv = {1, 0, 2}, k = 1, d1 = {"\u00008\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\t\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0007\n\u0002\u0018\u0002\n\u0002\u0018\u0002\n\u0002\b\u0002\n\u0002\u0018\u0002\n\u0000\n\u0002\u0010\u0002\n\u0000\n\u0002\u0018\u0002\n\u0002\b\u0003\b\u0017\u0018\u00002\u00020\u0001B\u0005\u00a2\u0006\u0002\u0010\u0002J\u000e\u0010\u0013\u001a\b\u0012\u0004\u0012\u00020\u00150\u0014H\u0016J\u000e\u0010\u0016\u001a\b\u0012\u0004\u0012\u00020\f0\u000bH\u0016J\b\u0010\u0017\u001a\u00020\u0018H\u0016J\u0012\u0010\u0019\u001a\u00020\u001a2\b\u0010\u001b\u001a\u0004\u0018\u00010\u001cH\u0014J\u0012\u0010\u001d\u001a\u00020\u001a2\b\u0010\u001e\u001a\u0004\u0018\u00010\u0015H\u0016R \u0010\u0003\u001a\u00020\u00048\u0016@\u0016X\u0097.\u00a2\u0006\u0010\n\u0002\u0010\t\u001a\u0004\b\u0005\u0010\u0006\"\u0004\b\u0007\u0010\bR\"\u0010\n\u001a\u0010\u0012\f\u0012\n \r*\u0004\u0018\u00010\f0\f0\u000bX\u0096\u0004\u00a2\u0006\b\n\u0000\u001a\u0004\b\u000e\u0010\u000fR \u0010\u0010\u001a\u00020\u00048\u0016@\u0016X\u0097.\u00a2\u0006\u0010\n\u0002\u0010\t\u001a\u0004\b\u0011\u0010\u0006\"\u0004\b\u0012\u0010\b\u00a8\u0006\u001f"}, d2 = {"Ledu/pjatk/unikino/ui/MainView;", "Lcom/vaadin/ui/UI;", "()V", "filmRepository", "error/NonExistentClass", "getFilmRepository", "()Lerror/NonExistentClass;", "setFilmRepository", "(Lerror/NonExistentClass;)V", "Lerror/NonExistentClass;", "grid", "Lcom/vaadin/ui/Grid;", "Ledu/pjatk/unikino/Seans;", "kotlin.jvm.PlatformType", "getGrid", "()Lcom/vaadin/ui/Grid;", "seansRepository", "getSeansRepository", "setSeansRepository", "createComboBoxWithFilm", "Lcom/vaadin/ui/ComboBox;", "Ledu/pjatk/unikino/Film;", "createGridWithSeans", "createMainLayout", "Lcom/vaadin/ui/Layout;", "init", "", "request", "Lcom/vaadin/server/VaadinRequest;", "update", "film", "gui"})
@com.vaadin.spring.annotation.SpringUI()
public class MainView extends com.vaadin.ui.UI {
    @org.jetbrains.annotations.NotNull()
    @org.springframework.beans.factory.annotation.Autowired()
    public error.NonExistentClass filmRepository;
    @org.jetbrains.annotations.NotNull()
    @org.springframework.beans.factory.annotation.Autowired()
    public error.NonExistentClass seansRepository;
    @org.jetbrains.annotations.NotNull()
    private final com.vaadin.ui.Grid<edu.pjatk.unikino.Seans> grid = null;
    
    @org.jetbrains.annotations.NotNull()
    public error.NonExistentClass getFilmRepository() {
        return null;
    }
    
    public void setFilmRepository(@org.jetbrains.annotations.NotNull()
    error.NonExistentClass p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public error.NonExistentClass getSeansRepository() {
        return null;
    }
    
    public void setSeansRepository(@org.jetbrains.annotations.NotNull()
    error.NonExistentClass p0) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public com.vaadin.ui.Grid<edu.pjatk.unikino.Seans> getGrid() {
        return null;
    }
    
    @java.lang.Override()
    protected void init(@org.jetbrains.annotations.Nullable()
    com.vaadin.server.VaadinRequest request) {
    }
    
    @org.jetbrains.annotations.NotNull()
    public com.vaadin.ui.Layout createMainLayout() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public com.vaadin.ui.ComboBox<edu.pjatk.unikino.Film> createComboBoxWithFilm() {
        return null;
    }
    
    @org.jetbrains.annotations.NotNull()
    public com.vaadin.ui.Grid<edu.pjatk.unikino.Seans> createGridWithSeans() {
        return null;
    }
    
    public void update(@org.jetbrains.annotations.Nullable()
    edu.pjatk.unikino.Film film) {
    }
    
    public MainView() {
        super();
    }
}